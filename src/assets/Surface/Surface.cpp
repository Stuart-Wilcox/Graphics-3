#include <cstdio>
#include "Surface.hpp"


Surface::Surface(const Point &p1, const Point &p2, const Point &p3){
  this->p1 = p1;
  this->p2 = p2;
  this->p3 = p3;
}

Surface Surface::translate(Point point){
  return Surface(
    this->p1.translate(point),
    this->p2.translate(point),
    this->p3.translate(point)
  );
}

Surface Surface::rotateX(double angle){
  return Surface(
    this->p1.rotateX(angle),
    this->p2.rotateX(angle),
    this->p3.rotateX(angle)
  );
}

Surface Surface::rotateY(double angle){
  return Surface(
    this->p1.rotateY(angle),
    this->p2.rotateY(angle),
    this->p3.rotateY(angle)
  );
}

Surface Surface::rotateZ(double angle){
  return Surface(
    this->p1.rotateZ(angle),
    this->p2.rotateZ(angle),
    this->p3.rotateZ(angle)
  );
}

void Surface::print(){
  printf("Surface ");
	printf("(%f, %f, %f)", this->p1.x, this->p1.y, this->p1.z);
  printf(" - ");
	printf("(%f, %f, %f)", this->p2.x, this->p2.y, this->p2.z);
  printf(" - ");
	printf("(%f, %f, %f)\n", this->p3.x, this->p3.y, this->p3.z);
}
