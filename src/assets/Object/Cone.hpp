#ifndef CONE_H
#define CONE_H

#include "Object.hpp"

/*
 * Represents a cone object in 3D space
 */
 class Cone: public Object{
 private:
  double resolution; // how many points on the circle on the base
 public:
   /*
   * Creates a new cone with height and redius given
   */
   Cone(double, double);
 };

#endif
