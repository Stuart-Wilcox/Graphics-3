#ifndef POINT_H
#define POINT_H

/*
 * Represents a point in 3D space.
 * Points are immutable, so any translation or rotation will return a new point without modifying the current point
 * */
class Point {
public:
	double x;
	double y;
	double z;

	/*
	 * Creates a new point at the origin
	 * */
	Point(){
		this->x = 0.0;
		this->y = 0.0;
		this->z = 0.0;
	}

	/*
	 * Creates a new point at the given X,Y and Z coordinates
	 * */
	Point(double, double, double);

	/*
	 * Rotates the point about the X-Axis by the given amount of degrees
	 * */
	Point rotateX(double);

	/*
	 * Rotates the point about the Y-Axis by the given amount of degrees
	 * */
	Point rotateY(double);

	/*
	 * Rotates the point about the Z-Axis by the given amount of degrees
	 * */
	Point rotateZ(double);

	/*
	 * Translates the point, using the given point as a direction vector
	 * */
	Point translate(Point);

	/*
	 * Prints the point to stdout
	 * */
	void print();
};

#endif
