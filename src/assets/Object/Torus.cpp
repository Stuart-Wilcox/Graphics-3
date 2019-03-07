#include <vector>
#include "Torus.hpp"

Torus::Torus(double innerRadius, double outerRadius){
  this->resolution = 45;

  const double angle = 360.0 / this->resolution;

  Point p(0.0, innerRadius, 0.0);
  std::vector<Point> circle;

  // make a circle around origin in XZ plane
  for(int i = 0; i < this->resolution; i++){
    p = p.rotateX(angle);
    circle.push_back(p);
  }

  // move the circle in the Z direction
  for(int i = 0; i < this->resolution; i++){
    circle[i] = circle[i].translate(Point(0.0,0.0,outerRadius));
  }

  // use this to create a second circle, and successively join segments between the two circles
  std::vector<Point> circle2;

  for(int i = 0; i < this->resolution; i++){
    p = circle[i].rotateY(angle);
    circle2.push_back(p);
  }

  for(int j = 0; j < this->resolution; j++){
    for(int i = 1; i < this->resolution; i++){
      // order is super important here! Do no change
      this->addSurface(Surface(circle2[i-1],circle[i],circle[i-1]));
      this->addSurface(Surface(circle[i],circle2[i-1],circle2[i]));
    }
    this->addSurface(Surface(circle2[this->resolution-1],circle[0],circle[this->resolution-1]));
    this->addSurface(Surface(circle[0],circle2[this->resolution-1],circle2[0]));

    for(int i = 0; i < this->resolution; i++){
      circle[i] = circle2[i];
      circle2[i] = circle2[i].rotateY(angle);
    }
  }
}
