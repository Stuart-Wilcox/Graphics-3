#ifndef OBJECT_H
#define OBJECT_H

#include <cstdio>
#include <set>
#include <vector>
#include "../Surface/Surface.hpp"
#include "../Point/Point.hpp"

/*
 * Represents an abstract 3D object, which is a collection of vertices
 * */
class Object {
protected:
	std::set<Point> points;
	std::vector<Surface> surfaces;
	unsigned long colour;
public:

	/*
	 * Creates a new object with no vertices
	 * */
	Object();

	/*
	 * Adds a Edge to the object's vertices
	 * */
	void addSurface(Surface);

	/*
	 * Returns a vector of the object's vertices
	 * */
	std::vector<Surface> getSurfaces();

	/*
	 * Translates the object, using the given point as a direction vector
	 * This modifies the object permanently
	 * */
	void translate(Point);

	/*
	 * Rotates the object about the X-Axis by the given amount of degrees
	 * This modifies the object permanently
	 * */
	void rotateX(double);

	/*
	 * Rotates the object about the Y-Axis by the given amount of degrees
	 * This modifies the object permanently
	 * */
	void rotateY(double);

	/*
	 * Rotates the object about the Z-Axis by the given amount of degrees
	 * This modifies the object permanently
	 * */
	void rotateZ(double);

	/*
	 * Prints the object to stdout
	 * */
	void print();

	void printPoints(){
		printf("%i\n", this->points.size());
		for(std::set<Point>::iterator it=this->points.begin(); it!=this->points.end();++it){
			Point p = *it;
			p.print();
		}
	}

	void setColour(unsigned long colour){
		this->colour = colour;
	}

	unsigned long getColour(){
		return this->colour;
	}
};

#endif
