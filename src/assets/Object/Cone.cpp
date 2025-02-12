#include <cstdio>
#include <cmath>
#include <vector>
#include "Cone.hpp"


Cone::Cone(double radius, double height){
  this->resolution = 35;

  const double angle = 360.0 / this->resolution;

  std::vector<Point> circle;
  Point p(0.0,0.0,radius);
  circle.push_back(p);

  // figure out the points on the circle
  for(int i = 1; i < this->resolution; i++){
    p = p.rotateY(-1.0*angle);
    circle.push_back(p);
  }

  Point top(0.0,height,0.0);
  Point centre(0.0,0.0,0.0);

  this->addSurface(Surface(circle[this->resolution-1], circle[0], top));
  // hollow-bottom cone
  //this->addSurface(Surface(circle[0], circle[this->resolution-1], centre));
  for(int i = 1; i <= this->resolution; i++){
    this->addSurface(Surface(circle[i-1], circle[i], top));
    // hollow-bottom cone
    //this->addSurface(Surface(circle[i-1], circle[i], centre));
  }
}
