#include <cstdio>
#include "Scene.hpp"

Scene::Scene(): objects(){

}

void Scene::addObject(Object object){
	this->objects.push_back(object);
}

std::vector<Object> Scene::getObjects(){
	return this->objects;
}

void Scene::print(){
	printf("Scene\n");
	for(int i = 0; i < this->objects.size(); i++){
		printf("\t");
		this->objects[i].print();
	}
}
