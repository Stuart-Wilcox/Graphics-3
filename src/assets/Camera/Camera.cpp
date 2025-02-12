#include <cmath>
#include <vector>
#include <cstdio>
#include "Camera.hpp"

#define PI 3.141592

Camera::Camera(): camera(3,3), position(0,0,0), orientation(0,0,0) {}

Camera::Camera(Point position, double angleX, double angleY, double angleZ): camera(3,3), position(0,0,0), orientation(0,0,0) {
  angleX = (PI * angleX) / 180.0;
  angleY = (PI * angleY) / 180.0;
  angleZ = (PI * angleZ) / 180.0;

  this->position.x = position.x;
  this->position.y = position.y;
  this->position.z = position.z;

  double c1[3][3] = {
    { 1, 0, 0 },
    { 0, cos(angleX), sin(angleX) },
    { 0, -1.0*sin(angleX), cos(angleX) }
  };

  double c2[3][3] = {
    { cos(angleY), 0, -1.0*sin(angleY) },
    { 0, 1, 0 },
    { sin(angleY), 0, cos(angleY) }
  };

  double c3[3][3] = {
    { cos(angleZ), sin(angleZ), 0 },
    { -1.0*sin(angleZ), cos(angleZ), 0 },
    { 0, 0, 1 }
  };

  Matrix m1(3,3);
  Matrix m2(3,3);
  Matrix m3(3,3);

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      m1[i][j] = c1[i][j];
      m2[i][j] = c2[i][j];
      m3[i][j] = c3[i][j];
    }
  }

  this->camera = m1 * m2 * m3;
}

Scene Camera::projectScene(Scene scene){
  Scene s;
  std::vector<Object> o = scene.getObjects();
  for(int i = 0; i < o.size(); i++){
    s.addObject(this->projectObject(o[i]));
  }
  return s;
}

Object Camera::projectObject(Object object){
  Object o;
  o.setColour(object.getColour().red, object.getColour().green, object.getColour().blue);
  std::vector<Surface> s = object.getSurfaces();
  for(int i = 0; i < s.size(); i++){
    o.addSurface(this->projectSurface(s[i]));
  }
  return o;
}

Surface Camera::projectSurface(Surface surface){
  return Surface(this->projectPoint(surface.p1), this->projectPoint(surface.p2), this->projectPoint(surface.p3));
}

Point Camera::projectPoint(Point point){
  Point a = this->position;
  Point b(0,0,0);
  Point c = point;
  Point d(0,0,0);
  Point e(0,0, 300.0);

  Matrix tempA = Matrix::fromPoint(a);
  Matrix tempC = Matrix::fromPoint(c);
  Matrix tempDiff = tempA - tempC;
  Matrix tempD = this->camera * tempDiff;

  d = Matrix::toPoint(tempD);

  b.x = (d.x*(e.z/d.z)) + e.x;
  b.y = (d.y*(e.z/d.z)) + e.y;
  b.z = (point.z);
  // b.x = (c.x - a.x) * (factor * (b.z - a.z) / (c.z - a.z));
  // b.y = (c.y - a.y) * (factor * (b.z - a.z) / (c.z - a.z));

  b.x += 256;
  b.y += 256;

  return b;
}
