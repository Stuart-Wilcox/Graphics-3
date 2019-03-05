#include <vector>
#include "Sphere.hpp"

Sphere::Sphere(double radius){
  this->resolution = 7;

  const double angle = 180.0 / (double)this->resolution;

  Point p(0.0, radius, 0.0);
  std::vector<Point> semiCircle;

  semiCircle.push_back(p);
  for(int i = 0; i < this->resolution; i++){
    p = p.rotateX(angle);
    semiCircle.push_back(p);
  }

  std::vector<Point> semiCircle2;
  for(int i = 0; i <= this->resolution; i++){
    p = semiCircle[i].rotateY(angle);
    semiCircle2.push_back(p);
  }

  for(int j = 0; j < 2*this->resolution; j++){
    for(int i = 1; i <= this->resolution; i++){
      this->addSurface(Surface(semiCircle[i],semiCircle[i-1],semiCircle2[i-1]));
      this->addSurface(Surface(semiCircle2[i],semiCircle2[i-1],semiCircle[i]));
    }


    for(int i = 0; i < this->resolution; i++){
      semiCircle[i] = semiCircle2[i];
      semiCircle2[i] = semiCircle2[i].rotateY(angle);
    }
  }
}
