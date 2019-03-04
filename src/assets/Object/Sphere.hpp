#ifndef SPHERE_H
#define SPHERE_H

#include "Object.hpp"
#include "../Point/Point.hpp"

/*
 * Represents a sphere object in 3D space
 * */
class Sphere: public Object {
private:
	double radius;
	double resolution; // how many points per line on the circle?
public:
	/*
	 * Creates a new sphere with given radius. The sphere is has its centre at the origin.
	 * */
	Sphere(double radius);
};

#endif
