#include <stdio.h>
#include <stdlib.h>

#include "utils/Window/MyWindow.hpp"
#include "assets/Camera/Camera.hpp"
#include "assets/Scene/Scene.hpp"
#include "assets/Object/Sphere.hpp"
#include "assets/Object/Torus.hpp"
#include "assets/Object/Cone.hpp"

Scene getScene();
Camera getCamera1();
Camera getCamera2();
Camera getCamera3();
Camera getCamera4();
Camera getCamera5();

int main(int argc, char *argv[]){
	MyWindow window; // create a window

	window.scene = getScene(); // set the window's scene

	/* CHANGE BELOW LINE TO USE A DIFFERENT CAMERAS */
	window.camera = getCamera5(); // set the window's camera

	window.show(); // map and display graphic

	return 0;
}

Scene getScene(){
	// create spere of radius 175
	Sphere s1(175.0);
	// red=255,green=0,blue=0
	s1.setColour(255, 0, 0);
	// move the sphere
  s1.translate(Point(250.0, 100.0, -500.0));

	// create torus of tube radius 75, circle radius 200
  Torus t1(75.0, 200.0);
	// red=0,green=255,blue=0
	t1.setColour(0, 255, 0);
	// move the torus
	t1.translate(Point(-75.0, -150.0, -400.0));

	// create a cone with bottom radius 150, height 175
	Cone c1(150.0, 175.0);
	// red=0,green=0,blue=255
	c1.setColour(0, 0, 255);
	// this does nothing for a cone
	c1.rotateY(180.0);
	// move the cone
	c1.translate(Point(-150.0, 150.0, -600.0));

	// add the objects to the scene
  Scene scene;
	scene.addObject(t1);
	scene.addObject(s1);
	scene.addObject(c1);

	// add a light source to the scene
	scene.setLightSource(Point(0.0, 100.0, -400.0));

	return scene;
}

Camera getCamera1(){
	return Camera(Point(0.0, 100.0, 0.0), 0.0, 0.0, 0.0);
}

Camera getCamera2(){
	return Camera(Point(450.0, 150.0, -450.0), 0.0, 90.0, 0.0);
}

Camera getCamera3(){
	return Camera(Point(0.0, 150.0, -900.0), 0.0, 180.0, 0.0);
}

Camera getCamera4(){
	return Camera(Point(-450.0, -300.0, -600.0), 45.0, 270.0, 0.0);
}

Camera getCamera5(){
	return Camera(Point(0.0, 400.0, 0.0), 315.0, 0.0, 0.0);
}
