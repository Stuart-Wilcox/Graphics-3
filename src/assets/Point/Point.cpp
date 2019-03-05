#include <cstdio>
#include "Point.hpp"
#include "../../utils/Matrix/Matrix.hpp"

Point::Point(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
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
