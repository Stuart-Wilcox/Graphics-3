#include <vector>
#include "Torus.hpp"

Torus::Torus(double innerRadius, double outerRadius){
  this->resolution = 32;

  const double angle = 360.0 / this->resolution;

  Point p(0.0, innerRadius, 0.0);
  std::vector<Point> circle;

  for(int i = 0; i < this->resolution; i++){
    p = p.rotateX(angle);
    circle.push_back(p);
  }

  for(int i = 0; i < this->resolution; i++){
    circle[i] = circle[i].translate(Point(0.0,0.0,outerRadius));
  }

  std::vector<Point> circle2;

  for(int i = 0; i < this->resolution; i++){
    p = circle[i].rotateY(angle);
    circle2.push_back(p);
  }

  for(int j = 0; j < this->resolution; j++){
    for(int i = 1; i < this->resolution; i++){
      this->addSurface(Surface(circle[i-1],circle[i],circle2[i-1]));
      this->addSurface(Surface(circle[i],circle2[i-1],circle2[i]));
    }

    for(int i = 0; i < this->resolution; i++){
      circle[i] = circle2[i];
      circle2[i] = circle2[i].rotateY(angle);
    }
  }
}
