#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

#include "../../assets/Scene/Scene.hpp"
#include "../../assets/Camera/Camera.hpp"

class MyWindow {
  private:
    Window rootWindow;
    Window window;
    GC gc;
    Display *display;
    int screen;
    int black;
    int white;

    /**
    * create a new window relying directly on XCreateSimpleWindow and return the result
    * @return { Window } The newly created window
    */
    Window createWindow();

    /**
    * initializes the window to standard values
    * not a necessary call to make once a window is created
    */
    void initializeWindow();

    /**
    * draw a single pixel at the specified point
    * @param { int } x The x coordinate of the point to draw
    * @param { int } y The y coordinate of the point to draw
    */
    void drawPixel(int x, int y);

    /**
     * draws a single pixel of the given colour at the specified point
     */
    void drawPixel(int x, int y, unsigned long colour);

    /**
     * fill a triangle given by int x1,int y1, int x2, int y2, int x3, int y3
     * @param { int } x1
     * @param { int } y1
     * @param { int } x2
     * @param { int } y2
     * @param { int } x3
     * @param { int } y3
     */
    void fillTriangle(int x1, int y1, int x2, int y2, int x3, int y3, unsigned long);

    /**
     *
     */
    void fillFlatBottomTriangle(int x1, int y1, int x2, int y2, int x3, int y3, unsigned long = 0);

    /**
     *
     */
    void fillFlatTopTriangle(int x1, int y1, int x2, int y2, int x3, int y3, unsigned long = 0);

    /**
    * draw a line between the points given by (x1, y1) and (x2, y2)
    * @param { int } x1 The x coordinate of the starting point of the line
    * @param { int } y1 The y coordinate of the starting point of the line
    * @param { int } x2 The x coordinate of the ending point of the line
    * @param { int } y2 The y coordinate of the ending point of the line
    */
    void drawLine(int x1, int y1, int x2, int y2, unsigned long = 0);

    /**
    * helper function to aid drawLine
    * draws a line that walks in x
    * @param { int } x1 The x coordinate of the starting point of the line
    * @param { int } y1 The y coordinate of the starting point of the line
    * @param { int } x2 The x coordinate of the ending point of the line
    * @param { int } y2 The y coordinate of the ending point of the line
    */
    void drawLineLow(int x1, int y1, int x2, int y2, unsigned long = 0);

    /**
    * helper function to aid drawLine
    * draws a line that walks in y
    * @param { int } x1 The x coordinate of the starting point of the line
    * @param { int } y1 The y coordinate of the starting point of the line
    * @param { int } x2 The x coordinate of the ending point of the line
    * @param { int } y2 The y coordinate of the ending point of the line
    */
    void drawLineHigh(int x1, int y1, int x2, int y2, unsigned long = 0);

  public:
    Scene scene;
    Camera camera;

    /**
    * default constructor, creates and initializes window, but does not display it
    */
    MyWindow();

    /**
    * visually display the window to the screen, this also calls the draw method when the time is right
    */
    void show();

    /**
    * draw the needed graphic to the display. in this case it is a long spiral (looks like a bunch of circles)
    */
    void draw();

    /**
     * draws the given scene to the display
     */
    void drawScene();

    /**
    * close the window and destroy it. Window cannot be re-made after this
    */
    void close();
};

#endif
