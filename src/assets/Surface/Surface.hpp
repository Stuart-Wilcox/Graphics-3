#ifndef SURFACE_H
#define SURFACE_H

#include "../Edge/Edge.hpp"
#include "../Point/Point.hpp"

class Surface {
public:
  Point p1;
  Point p2;
  Point p3;

  Surface(const Point &p1, const Point &p2, const Point &p3);

  Point calcNormal();

  Point calcCentroid();

  unsigned long calcShade(unsigned long colour, Point lightSource);

  Surface translate(Point);

  Surface rotateX(double);

  Surface rotateY(double);

  Surface rotateZ(double);

  void print();
};

#endif
