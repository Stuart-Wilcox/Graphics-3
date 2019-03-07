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
	window.camera = getCamera1(); // set the window's camera


	window.show(); // map and display graphic

	return 0;
}

Scene getScene(){
	Sphere s1(175.0);
	s1.setColour(334l);
  //s1.rotateY(90.0);
  s1.translate(Point(0.0, 0.0, -500.0));

  Torus t1(75.0, 200.0);
	t1.rotateX(22.5);
  t1.translate(Point(0.0, 0.0, -550.0));
	t1.setColour(281l);

	// Cone c1(150.0, 175.0);
	// c1.translate(Point(100, 0.0, -500.0));
	// c1.setColour(255l);

  Scene scene;
  scene.addObject(t1);

	scene.setLightSource(Point(0, -100, -400));

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
