#include <cstdio>
#include <cmath>
#include "Point.hpp"
#include "../../utils/Matrix/Matrix.hpp"

Point::Point(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
}

double Point::calcMagnitude(){
	return sqrt((this->x*this->x) + (this->y*this->y) + (this->z*this->z));
}

Point Point::cross(Point p){
	// 23 31 12
	return Point(
		(this->y*p.z) - (this->z*p.y),
		(this->z*p.x) - (this->x*p.z),
		(this->x*p.y) - (this->y*p.x)
	);
}

double Point::dot(Point p){
	return (this->x*p.x) + (this->y*p.y) + (this->z*p.z);
}

Point Point::normalize(){
	double magnitude = this->calcMagnitude();

	return Point(
		this->x / magnitude,
		this->y / magnitude,
		this->z / magnitude
	);
}

void Point::print(){
	printf("Point (%f, %f, %f)\n", this->x, this->y, this->z);
}

Point Point::rotateX(double angle){
	Matrix rot = Matrix::getXRotation(angle);
	Matrix pt = Matrix::fromPoint((*this));

	Matrix newPt = rot * pt;

	return Point(newPt[0][0],newPt[1][0],newPt[2][0]);
}

Point Point::rotateY(double angle){
	Matrix rot = Matrix::getYRotation(angle);
	Matrix pt = Matrix::fromPoint((*this));

	Matrix newPt = rot * pt;

	return Point(newPt[0][0], newPt[1][0], newPt[2][0]);
}

Point Point::rotateZ(double angle){
	Matrix rot = Matrix::getZRotation(angle);
	Matrix pt = Matrix::fromPoint((*this));

	Matrix newPt = rot * pt;

	return Point(newPt[0][0], newPt[1][0], newPt[1][0]);
}

Point Point::translate(Point direction){
	return Point(this->x + direction.x, this->y + direction.y, this->z + direction.z);
}

bool Point::operator<(const Point &rhs){
	if(rhs.x == this->x && rhs.y == this->y && rhs.z == this->z){
		return false;
	}
	return true;
}

const bool Point::operator<(const Point &rhs) const {
	const double epsilon = 0.5;
	bool x = std::abs(rhs.x - this->x) < epsilon;
	bool y = std::abs(rhs.y - this->y) < epsilon;
	bool z = std::abs(rhs.z - this->z) < epsilon;

	if(x && y && z){
		return false;
	}

	if(!x){
		return this->x < rhs.x;
	}
	else if(!y){
		return this->y < rhs.y;
	}
	else{
		return this->z < rhs.z;
	}
}
