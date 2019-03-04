#ifndef EDGE_H
#define EDGE_H

#include "../Point/Point.hpp"

/*
 * Represents a line in 3D space. It is simply a connection between two points
 * Is immutable!
 * */
class Edge {
public:
	Point p1;
	Point p2;

	/*
	 * Creates a new vertex between the given points
	 * */
	Edge(const Point &a, const Point &b);

	/*
	 * Translates the vertex, using the given point as direction vector
	 * */
	Edge translate(Point);

	/*
	 * Rotates the vertex about the X-Axis by the given amount of degrees
	 * */
	Edge rotateX(double);

	/*
	 * Rotates the vertex about the Y-Axis by the given amount of degrees
	 * */
	Edge rotateY(double);

	/*
	 * Rotates the vertex about the Z-Axis by the given amount of degrees
	 * */
	Edge rotateZ(double);

	/*
	 * Prints the vertex to stdout
	 * */
	void print();
};

#endif
