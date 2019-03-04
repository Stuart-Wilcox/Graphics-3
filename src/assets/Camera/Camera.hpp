#ifndef CAMERA_H
#define CAMERA_H

#include "../../utils/Matrix/Matrix.hpp"
#include "../Point/Point.hpp"
#include "../Edge/Edge.hpp"
#include "../Object/Object.hpp"
#include "../Scene/Scene.hpp"

/*
 * Represents a camera object, which captures the 3D scene and provides the projection ont the screen
 */
class Camera {
public:
  Matrix camera;
  Point position;
  Point orientation;

  /*
   * Projects a single point
   */
   Point projectPoint(Point);

   /*
    * Projects a single vertex
    */
    Edge projectEdge(Edge);

    /*
     * Projects a single object
     */
     Object projectObject(Object);

public:
  /*
   * Default ctor
   */
  Camera();

  /*
   * Creates a new camera at the given point, with Tait-Bryan angles given
   */
  Camera(Point, double, double, double);

  /*
   * Finds the projection of the objects in the given scene and returns a new scene with the modified objects
   */
   Scene projectScene(Scene);
};

#endif
