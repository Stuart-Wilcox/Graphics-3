#include "Coordinates.hpp"
#include "../Point/Point.hpp"

Coordinates::Coordinates(){
	Point origin(0,0,0);

	Point xMax(1024,0,0);
	Point xMin(-1024,0,0);
	Point yMax(0,1024,0);
	Point yMin(0,-1024,0);
	Point zMax(0,0,1024);
	Point zMin(0,0,-1024);

	this->addEdge(Edge(origin, xMax));
	this->addEdge(Edge(origin, xMin));
	this->addEdge(Edge(origin, yMax));
	this->addEdge(Edge(origin, yMin));
	this->addEdge(Edge(origin, zMax));
	this->addEdge(Edge(origin, zMin));
}
