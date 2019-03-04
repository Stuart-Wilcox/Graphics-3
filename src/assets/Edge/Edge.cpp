#include <cstdio>
#include "Edge.hpp"
#include "../Point/Point.hpp"

Edge::Edge(const Point &p1, const Point &p2): p1(p1), p2(p2) {
	this->p1 = p1;
	this->p2 = p2;
}

Edge Edge::translate(Point direction){
	return Edge(this->p1.translate(direction), this->p2.translate(direction));
}

Edge Edge::rotateX(double angle){
	return Edge(this->p1.rotateX(angle), this->p2.rotateX(angle));
}

Edge Edge::rotateY(double angle){
	return Edge(this->p1.rotateY(angle), this->p2.rotateY(angle));
}

Edge Edge::rotateZ(double angle){
	return Edge(this->p1.rotateZ(angle), this->p2.rotateZ(angle));
}

void Edge::print(){
	printf("Edge ");
	printf("(%f, %f, %f)", this->p1.x, this->p1.y, this->p1.z);
	printf(" to ");
	printf("(%f, %f, %f)\n", this->p2.x, this->p2.y, this->p2.z);
}
