#include <cstdio>
#include <cmath>
#include <vector>
#include "MyWindow.hpp"
#include "../../assets/Camera/Camera.hpp"
#include "../../assets/Scene/Scene.hpp"

void swap(int& a, int& b){
  int temp = a;
  a = b;
  b = temp;
}

// default constructor
MyWindow::MyWindow(){
  display = XOpenDisplay((char *)0); // create a display. Connect to XServer

  // make sure that actually worked. if not, give up and print error message
  if(display == NULL){
    fprintf(stderr, "Cannot open display");
    return;
  }

  // initialize member variables
  screen = DefaultScreen(display);
  black = BlackPixel(display, screen);
  white = WhitePixel(display, screen);

  // create a root window
  rootWindow = RootWindow(display, screen);

  // use member function to create a new window
  window = createWindow();

  // tell X what input you are willing to accept, in this case Exposure, KeyPress and ButtonPress (clicking)
  XSelectInput(display, window, ExposureMask | KeyPressMask | ButtonPressMask);

  // initialize graphics context. this will be used as default graphics settings in later calls
  gc = XCreateGC(display, window, 0, 0);

  // set defaults to the window
  initializeWindow();
}

// helper function
Window MyWindow::createWindow(){
  // use X to make a window and return it
  return XCreateSimpleWindow(display, rootWindow, 300, 300, 512, 512, 5, black, white);
}

// must be called before using any graphics stuff
void MyWindow::initializeWindow(){
  // set default properties to the window
  XSetStandardProperties(display, window, "My Window", "Hi!", None, NULL, 0, NULL);
	XSetBackground(display, gc, white);
	XSetForeground(display, gc, black);
	XSetFillStyle(display, gc, FillSolid);
}

// call this to show the contents of this.draw()
void MyWindow::show(){
  // map the window, then wait until the event "expose" occurs before calling draw
  XMapWindow(display, window);

  XEvent event; // var to hold events as they come up
	KeySym key; // needed to get key input
	char text[255]; // hold key input
  bool complete = false;

	while(1){
		XNextEvent(display, &event); // get an event from the window, place into 'event'. This call blocks until an event is captured

		if(event.type == Expose && event.xexpose.count == 0 && !complete){
			drawScene();
			XFlush(display);
      complete = true;
		}

		if(event.type == KeyPress && XLookupString(&event.xkey, text, 255, &key, 0) == 1){
			printf("You pressed the %c key!\n", text[0]);
      if(text[0] == 'q'){
        close();
        break;
      }
		}

		if(event.type == ButtonPress){
			printf("You pressed a button at (%i, %i)\n", event.xbutton.x, event.xbutton.y);
		}
  }
}

// close the window
void MyWindow::close(){
  XFreeGC(display, gc);
  XDestroyWindow(display, window);
  XCloseDisplay(display);
}

void MyWindow::drawScene(){
  Scene projected = camera.projectScene(scene);
  Point lightSource = scene.getLightSource();

  std::vector<Object> objects = projected.getObjects();
  for(int i = 0; i < objects.size(); i++){
    Object object = objects[i];
    XColor objectColour = object.getColour();
    std::vector<Surface> surfaces = object.getSurfaces();

    for(int j = 0; j < surfaces.size(); j++){
      Surface s = surfaces[j];
      XColor surfaceColour = s.calcShade(objectColour, lightSource);

      // calculate the colour based on the XColor
      // dont ask why this works. took lots of trial and error...
      unsigned long colour = (surfaceColour.blue) + (surfaceColour.green << 8) + (surfaceColour.red << 16);

      fillTriangle((int)(s.p1.x), (int)(s.p1.y), (int)(s.p2.x), (int)(s.p2.y), (int)(s.p3.x), (int)(s.p3.y), colour);

      // uncomment this to draw the lines on the objects
      //drawLine((int)(s.p1.x), (int)(s.p1.y), (int)(s.p2.x), (int)(s.p2.y));
      //drawLine((int)(s.p1.x), (int)(s.p1.y), (int)(s.p3.x), (int)(s.p3.y));
      //drawLine((int)(s.p2.x), (int)(s.p2.y), (int)(s.p3.x), (int)(s.p3.y));
    }
  }
}

void MyWindow::fillTriangle(int x1, int y1, int x2, int y2, int x3, int y3, unsigned long surfaceColour){
  int yMax = y1, xMax = x1, yMid = y2, xMid = x2, yMin = y3, xMin = x3;

  // sort the xy coordinates to know which are larger than others
  if(yMin > yMid){
    swap(yMin, yMid);
    swap(xMin, xMid);
  }
  if(yMid > yMax){
    swap(yMid, yMax);
    swap(xMid, xMax);
  }
  if(yMin > yMid){
    swap(yMin, yMid);
    swap(xMin, xMid);
  }

  if(yMin == yMid){
    fillFlatBottomTriangle(xMax, yMax, xMid, yMid, xMin, yMin, surfaceColour);
  }
  else if(yMax == yMin){
    fillFlatTopTriangle(xMax, yMax, xMid, yMid, xMin, yMin, surfaceColour);
  }
  else {
    // split the triangle into twwo triangles, one with flat top and one with flat bottom
    int yNew, xNew;

    xNew = (int)(xMax + ((double)(yMid - yMax) / (double)(yMin - yMax)) * (xMin - xMax));
    yNew = yMid;

    fillFlatBottomTriangle(xMax, yMax, xMid, yMid, xNew, yNew, surfaceColour);
    fillFlatTopTriangle(xNew, yNew, xMid, yMid, xMin, yMin, surfaceColour);
  }
}

void MyWindow::fillFlatBottomTriangle(int x1, int y1, int x2, int y2, int x3, int y3, unsigned long colour){
  // make sure we dont get a divide by zero error
  if(y1 == y2) y1++;
  if(y2 == y3) y3--;

  // inverse slope
  double m1 = (double)(x1-x2)/(double)(y1-y2);
  double m2 = (double)(x1-x3)/(double)(y1-y3);

  // current x position on each arm of the triangle
  double cx1 = x2;
  double cx2 = x3;

  for(int i = y2; i < y1; i++){
    drawLine((int)cx1, i, (int)cx2, i, colour);
    cx1 += m1;
    cx2 += m2;
  }
}

void MyWindow::fillFlatTopTriangle(int x1, int y1, int x2, int y2, int x3, int y3, unsigned long colour){
  // make sure we dont get a divide by zero error
  if(y1 == y3) y1++;
  if(y2 == y3) y3--;

  // inverse slope
  double m1 = (double)(x1-x3)/(double)(y1-y3);
  double m2 = (double)(x2-x3)/(double)(y2-y3);

  // current x position on each arm of the triangle
  double cx1 = x1;
  double cx2 = x2;

  for(int i = y1; i > y3; i--){
    drawLine((int)cx1, i, (int)cx2, i, colour);
    cx1 -= m1;
    cx2 -= m2;
  }
}

// bresenham's algorithm
void MyWindow::drawLine(int x1, int y1, int x2, int y2, unsigned long colour){
  if(abs(y2 - y1) < abs(x2 - x1)){
    if(x1 > x2){
      // draw line low, reverse ends
      drawLineLow(x2, y2, x1, y1, colour);
    }
    else {
      // draw line low, normal
      drawLineLow(x1, y1, x2, y2, colour);
    }
  }
  else {
    if(y1 > y2){
      // draw line high, reverse ends
      drawLineHigh(x2, y2, x1, y1, colour);
    }
    else {
      // draw line low, reverse ends
      drawLineHigh(x1, y1, x2, y2, colour);
    }
  }
}

// helper for drawLine
void MyWindow::drawLineLow(int x1, int y1, int x2, int y2, unsigned long colour){
  int dx = x2 - x1;
  int dy = y2 - y1;
  int yi = 1;

  if(dy < 0){
    yi = -1;
    dy *= -1;
  }

  int D = (2 * dy) - dx;
  int y = y1;

  // walk in x
  for(int x = x1; x <= x2; x++){
    drawPixel(x, y, colour);
    if(D > 0){
      y += yi;
      D -= 2 * dx;
    }
    D += 2 * dy;
  }
}

// helper for drawLine
void MyWindow::drawLineHigh(int x1, int y1, int x2, int y2, unsigned long colour){
  int dx = x2 - x1;
  int dy = y2 - y1;
  int xi = 1;

  if(dx < 0){
    xi = -1;
    dx *= -1;
  }

  int D = (2 * dx) - dy;
  int x = x1;

  // walk in y
  for(int y = y1; y <= y2; y++){
    drawPixel(x, y, colour);
    if(D > 0){
      x += xi;
      D -= 2 * dy;
    }
    D += 2 * dx;
  }
}

// light one pixel at given position
void MyWindow::drawPixel(int x, int y){
  XSetForeground(display, gc, black); // draw pixel in black
  XDrawPoint(display, window, gc, x, y); // use lower level method to colour pixel
  XFlush(display); // flush to the display (could be optimized if only done once in draw(), but not an issue for now)
}

void MyWindow::drawPixel(int x, int y, unsigned long colour){
  XSetForeground(display, gc, colour); // draw pixel in black
  XDrawPoint(display, window, gc, x, y); // use lower level method to colour pixel
  XFlush(display); // flush to the display (could be optimized if only done once in draw(), but not an issue for now)
}
