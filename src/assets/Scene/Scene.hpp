#ifndef SCENE_H
#define SCENE_H


#include <vector>
#include "../Object/Object.hpp"

/*
 * Represents a 3D scene, which is just a space containing 3D objects
 * */
class Scene {
private:
	static const int MAX_X=1024;
	static const int MAX_Y=1024;
	static const int MAX_Z=1024;
	std::vector<Object> objects;

public:
	/*
	 * Creates a new empty scene
	 * */
	Scene();

	/*
	 * Adds the given object to the scene. Objects take care of their own coordinates
	 * */
	void addObject(Object);

	/*
	 * Returns the object in the scene
	 * */
	std::vector<Object> getObjects();

	/*
	 * Prints the scene to stdout
	 * */
	void print();
};

#endif
