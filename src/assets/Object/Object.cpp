#include <cstdio>
#include <vector>
#include "Object.hpp"
#include "../Edge/Edge.hpp"


Object::Object(): surfaces() {}

void Object::addSurface(Surface surface){
	Point points[3] = { surface.p1, surface.p2, surface.p3 };
	std::set<Point>::iterator it;

	// change the surface to replace points already on the object, or else add its unique points to the point set
	for(int i = 0; i < 3; i++){
		it = this->points.find(points[i]);
		if(it != this->points.end()){
			// points[i] is in the set already
			if(i == 0){
				surface.p1 = *it;
			}
			if(i == 1){
				surface.p2 = *it;
			}
			if(i == 2){
				surface.p3 = *it;
			}
		}
		else {
			// point p1 is not in the set
			this->points.insert(points[i]);
		}
	}

	if(this->surfaces.size() == 0){
		this->surfaces.push_back(surface); // first surface, no need for ordering
	}
	else {
		// insert the surface by depth
		double depth = surface.calcCentroid().z;
		double curr = this->surfaces[0].calcCentroid().z;

		for(std::vector<Surface>::iterator it = this->surfaces.begin(); it < this->surfaces.end(); it++){
			if(depth < curr){
				this->surfaces.insert(it, surface);
				return;
			}
			Surface s = *it;
			curr = s.calcCentroid().z;
		}
		this->surfaces.push_back(surface);
	}
}

std::vector<Surface> Object::getSurfaces(){
	return this->surfaces;
};


void Object::translate(Point direction){
	for(int i = 0; i < this->surfaces.size(); i++){
		this->surfaces[i] = this->surfaces[i].translate(direction);
	}
}

void Object::rotateX(double angle){
	for(int i = 0; i < this->surfaces.size(); i++){
		this->surfaces[i] = this->surfaces[i].rotateX(angle);
	}
}

void Object::rotateY(double angle){
	for(int i = 0; i < this->surfaces.size(); i++){
		this->surfaces[i] = this->surfaces[i].rotateY(angle);
	}
}

void Object::rotateZ(double angle){
	for(int i = 0; i < this->surfaces.size(); i++){
		this->surfaces[i] = this->surfaces[i].rotateZ(angle);
	}
}

void Object::print(){
	printf("Object\n");
	for(int i = 0; i < this->surfaces.size(); i++){
		printf("\t");
		this->surfaces[i].print();
	}
}
