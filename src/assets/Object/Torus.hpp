#ifndef TORUS_H
#define TORUS_H

#include "Object.hpp"

/*
 * Represents a torus object in 3D space
 * */
class Torus: public Object{
private:
	double resolution;
public:
	/*
	 * Creates a new torus with tube radius and outer radius given. The centre is at the origin.
	 * */
	Torus(double, double);
};

#endif
