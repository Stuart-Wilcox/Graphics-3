#include <cstdio>
#include <vector>
#include "Object.hpp"
#include "../Edge/Edge.hpp"


Object::Object(): edges() {
}

void Object::addEdge(Edge edge){
	this->edges.push_back(edge);
}

std::vector<Edge> Object::getEdges(){
	return this->edges;
};


void Object::translate(Point direction){
	for(int i = 0; i < this->edges.size(); i++){
		this->edges[i] = this->edges[i].translate(direction);
	}
}

void Object::rotateX(double angle){
	for(int i = 0; i < this->edges.size(); i++){
		this->edges[i] = this->edges[i].rotateX(angle);
	}
}

void Object::rotateY(double angle){
	for(int i = 0; i < this->edges.size(); i++){
		this->edges[i] = this->edges[i].rotateY(angle);
	}
}

void Object::rotateZ(double angle){
	for(int i = 0; i < this->edges.size(); i++){
		this->edges[i] = this->edges[i].rotateZ(angle);
	}
}

void Object::print(){
	printf("Object\n");
	for(int i = 0; i < this->edges.size(); i++){
		printf("\t");
		this->edges[i].print();
	}
}
