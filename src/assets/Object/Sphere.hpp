#ifndef SPHERE_H
#define SPHERE_H

#include "Object.hpp"

/**
 * Represents a sphere object in 3D space
 */
class Sphere: public Object{
private:
  double resolution; // how many lines of longitude and latitude on the sphere
public:
  /**
   * Creates a new sphere with radius given
   */
  Sphere(double);
};

#endif
