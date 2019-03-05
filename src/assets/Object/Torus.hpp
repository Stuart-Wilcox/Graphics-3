#ifndef TORUS_H
#define TORUS_H

#include "Object.hpp"

/**
 * Represents a torus object in 3D space
 */
class Torus: public Object{
private:
  double resolution; // how many lines of longitude and latitude on the sphere
public:
  /**
   * Creates a new torus with inner and outer radius given
   */
  Torus(double, double);
};

#endif
