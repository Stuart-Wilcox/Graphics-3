#ifndef OBJECT_H
#define OBJECT_H


#include <vector>
#include "../Edge/Edge.hpp"

/*
 * Represents an abstract 3D object, which is a collection of vertices
 * */
class Object {
protected:
	std::vector<Edge> edges;
public:
	/*
	 * Creates a new object with no vertices
	 * */
	Object();

	/*
	 * Adds a Edge to the object's vertices
	 * */
	void addEdge(Edge);

	/*
	 * Returns a vector of the object's vertices
	 * */
	std::vector<Edge> getEdges();

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
};

#endif
