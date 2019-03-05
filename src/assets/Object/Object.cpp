#include <cstdio>
#include <vector>
#include "Object.hpp"
#include "../Edge/Edge.hpp"


Object::Object(): surfaces() {
}

void Object::addSurface(Surface surface){
	Point points[3] = { surface.p1, surface.p2, surface.p3 };
	std::set<Point>::iterator it;

	for(int i = 0; i < 3; i++){
		it = this->points.find(points[i]);
		if(it != this->points.end()){
			//printf("Point already in set\t");
			//points[i].print();
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
			//printf("Point not in set\t");
			//points[i].print();
		}
	}

	this->surfaces.push_back(surface);
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
