#include <cmath>
#include <vector>
#include <cstdio>
#include "Camera.hpp"

#define PI 3.141592

Camera::Camera(): m1(4,4), m2(4,4), m3(4,4) { }

Camera::Camera(Point position, Point gaze, double near, double far): m1(4,4), m2(4,4), m3(4,4) {
  this->position = position;
  this->gaze = gaze;
  this->p = Point(0.0, 0.0, 1.0);

  // determine n
  this->n = Point(position.x - gaze.x, position.y - gaze.y, position.z - gaze.z);
  this->n = this->n.normalize();

  // determine u
  this->u = this->p.cross(this->n);
  this->u = this->u.normalize();

  // determine v
  this->v = this->n.cross(this->u);
  this->v = this->v.normalize();

  this->m1[0][0] = this->u.x;
  this->m1[0][1] = this->u.y;
  this->m1[0][2] = this->u.z;
  this->m1[0][3] = -1.0 * position.dot(this->u);

  this->m1[1][0] = this->v.x;
  this->m1[1][1] = this->v.y;
  this->m1[1][2] = this->v.z;
  this->m1[1][3] = -1.0 * position.dot(this->v);

  this->m1[2][0] = this->n.x;
  this->m1[2][1] = this->n.y;
  this->m1[2][2] = this->n.z;
  this->m1[2][3] = -1.0 * position.dot(this->n);

  this->m1[3][0] = 0.0;
  this->m1[3][1] = 0.0;
  this->m1[3][2] = 0.0;
  this->m1[3][3] = 1.0;

  this->a = -1.0 * (far + near) / (far - near);
  this->b = -2.0 * (far * near) / (far - near);

  double l = -256.0;
  double r = 256.0;
  double t = -256.0;
  double b = 256.0;

  this->m2[0][0] = 2.0 * near / (r - l);
  this->m2[0][1] = 0.0;
  this->m2[0][2] = (r + l) / (r - l);
  this->m2[0][3] = 0.0;

  this->m2[1][0] = 0.0;
  this->m2[1][1] = 2.0 * near / (t - b);
  this->m2[1][2] = (t + b) / (t - b);
  this->m2[1][3] = 0.0;

  this->m2[2][0] = 0.0;
  this->m2[2][1] = 0.0;
  this->m2[2][2] = this->a;
  this->m2[2][3] = this->b;

  this->m2[3][0] = 0.0;
  this->m2[3][1] = 0.0;
  this->m2[3][2] = -1.0;
  this->m2[3][3] = 0.0;

  double w = 512.0;
  double h = 512.0;

  this->m3[0][0] = w / 2.0;
  this->m3[0][1] = 0.0;
  this->m3[0][2] = 0.0;
  this->m3[0][3] = w / 2.0;

  this->m3[1][0] = 0.0;
  this->m3[1][1] = (-1.0) * (h / 2.0);
  this->m3[1][2] = 0.0;
  this->m3[1][3] = (-1.0 * (h / 2.0)) + h;

  this->m3[2][0] = 0.0;
  this->m3[2][1] = 0.0;
  this->m3[2][2] = 1.0;
  this->m3[2][3] = 0.0;

  this->m3[3][0] = 0.0;
  this->m3[3][1] = 0.0;
  this->m3[3][2] = 0.0;
  this->m3[3][3] = 1.0;
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
  o.setColour(object.getColour());
  std::vector<Surface> s = object.getSurfaces();
  for(int i = 0; i < s.size(); i++){
    o.addSurface(this->projectSurface(s[i]));
  }
  return o;
}

Surface Camera::projectSurface(Surface surface){
  return Surface(
    this->projectPoint(surface.p1),
    this->projectPoint(surface.p2),
    this->projectPoint(surface.p3)
  );
}

Point Camera::projectPoint(Point point){
  Matrix p(4,1);
  p[0][0] = point.x;
  p[1][0] = point.y;
  p[2][0] = point.z;
  p[3][0] = 1.0;

  Matrix t1 = this->m1 * p;
  //Matrix t2 = this->m2 * t1;
  Matrix t3 = this->m3 * t1;

  return Point(t3[0][0], t3[1][0], t3[2][0]);
}
