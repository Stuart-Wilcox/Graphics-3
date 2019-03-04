/* Simple test program for asset classes */
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include "assets/Point/Point.hpp"
#include "assets/Edge/Edge.hpp"
#include "assets/Object/Object.hpp"
#include "assets/Object/Sphere.hpp"
#include "assets/Object/Torus.hpp"
#include "assets/Scene/Scene.hpp"

void point();
void edge();
void object();
void sphere();
void torus();
void scene();

int main(){
	// uncomment one of these to inspect it working
	// point();
	// edge();
	// object();
	// sphere();
	// torus();
	// scene();
}

void point(){
	Point p1(0,0,0);
	Point p2(0,0,1);
	Point p3(1,1,1);

	p1.print();
	p2.print();
	p3.print();

	p2.rotateY(90.0).print();
	p3.translate(p2).print();
}

void edge(){
	Point p1(0,0,0);
	Point p2(0,0,1);
	Point p3(1,1,1);

	Edge v1(p1,p2);
	Edge v2(p1,p3);
	Edge v3(p2,p3);

	v1.print();
	v2.print();
	v3.print();

	v1.translate(p3).print();
	v3.rotateY(90.0).print();
}

void object(){
	Point p1(0,0,0);
	Point p2(1,0,0);
	Point p3(1,0,1);
	Point p4(0,0,1);
	Point p5(0,1,0);
	Point p6(1,1,0);
	Point p7(1,1,1);
	Point p8(0,1,1);

	Edge v1(p1,p2);
	Edge v2(p2,p3);
	Edge v3(p3,p4);
	Edge v4(p4,p1);

	Edge v5(p5,p6);
	Edge v6(p6,p7);
	Edge v7(p7,p8);
	Edge v8(p8,p1);

	Edge v9(p1,p5);
	Edge v10(p2,p6);
	Edge v11(p3,p7);
	Edge v12(p4,p8);

	Object o1;
	o1.addEdge(v1);
	o1.addEdge(v2);
	o1.addEdge(v3);
	o1.addEdge(v4);
	o1.addEdge(v5);
	o1.addEdge(v6);
	o1.addEdge(v7);
	o1.addEdge(v8);
	o1.addEdge(v9);
	o1.addEdge(v10);
	o1.addEdge(v11);
	o1.addEdge(v12);

	o1.print();
	o1.rotateY(90.0);
	o1.print();
	o1.translate(Point(3,0,0));
	o1.print();
}

void sphere(){
	Sphere s1(4.0);
	s1.print();
}

void torus(){
	Torus t1(4.0, 16.0);

	t1.print();
}

void scene(){
	Sphere s1(4.0);
	Torus t1(4.0, 16.0);

	Scene scene;
	scene.addObject(s1);
	scene.addObject(t1);

	scene.print();
}
