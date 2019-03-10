#ifndef SURFACE_H
#define SURFACE_H

#include <X11/Xlib.h>

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

  XColor calcShade(XColor colour, Point lightSource);

  Surface translate(Point);

  Surface rotateX(double);

  Surface rotateY(double);

  Surface rotateZ(double);

  void print();
};

#endif
