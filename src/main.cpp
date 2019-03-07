#include <stdio.h>
#include <stdlib.h>

#include "utils/Window/MyWindow.hpp"
#include "assets/Camera/Camera.hpp"
#include "assets/Scene/Scene.hpp"
#include "assets/Object/Sphere.hpp"
#include "assets/Object/Torus.hpp"
#include "assets/Object/Cone.hpp"

Scene getScene();
Camera getCamera();

int main(int argc, char *argv[]){
	MyWindow window; // create a window

	window.scene = getScene(); // set the window's scene

	window.camera = getCamera(); // set the window's camera

	window.show(); // map and display graphic

	return 0;
}

Scene getScene(){
	Sphere s1(175.0);
	s1.setColour(255l);
  s1.translate(Point(250.0, 100.0, -500.0));

  Torus t1(75.0, 200.0);
  t1.translate(Point(-75.0, -150.0, -400.0));
	t1.setColour(255l);

	Cone c1(150.0, 175.0);
	c1.rotateY(180.0);
	c1.translate(Point(-150.0, 150.0, -600.0));
	c1.setColour(255l);

  Scene scene;
	scene.addObject(t1);
	scene.addObject(s1);
	scene.addObject(c1);

	scene.setLightSource(Point(0.0, 100.0, -400.0));

	return scene;
}

Camera getCamera(){
	Point position(5.0,5.0,5.0);
	Point gaze(0.0,0.0,0.0);
	double near = 5.0;
	double far = 100.0;
	Camera cam(position, gaze, near, far);

	//cam.m1.print();
	//cam.m2.print();
	cam.m3.print();

	return cam;
}
