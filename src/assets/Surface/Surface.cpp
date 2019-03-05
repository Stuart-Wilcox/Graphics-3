#include <cstdio>
#include "Surface.hpp"
#include "../../utils/Matrix/Matrix.hpp"


Surface::Surface(const Point &p1, const Point &p2, const Point &p3){
  this->p1 = p1;
  this->p2 = p2;
  this->p3 = p3;
}

Point Surface::calcNormal(){
  // difference between two points
  Point vect1(
    this->p1.x-this->p2.x,
    this->p1.y-this->p2.y,
    this->p1.z-this->p2.z
  );

  // difference between other two points
  Point vect2(
    this->p3.x-this->p2.x,
    this->p3.y-this->p2.y,
    this->p3.z-this->p2.z
  );


  // 23 31 12
  // calculate cross product of two vectors to obtain normal
  Point normal(
    (vect1.y * vect2.z) - (vect1.z - vect2.y),
    (vect1.z * vect2.x) - (vect1.x - vect2.z),
    (vect1.x * vect2.y) - (vect1.y - vect2.x)
  );

  return normal;
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
