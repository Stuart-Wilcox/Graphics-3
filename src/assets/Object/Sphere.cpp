#include <cmath>
#include <math.h>
#include <cstdio>
#include <vector>
#include "Sphere.hpp"
#include "Object.hpp"

Sphere::Sphere(double radius) {
	this->resolution = 36;
	double angle = 360 / resolution;

	std::vector<Point> circle;
	Point p(0.0, 0.0, radius);
	circle.push_back(p);

	for(int i = 1; i < this->resolution; i++){
		p = p.rotateX(angle);
		circle.push_back(p);
	}

	// circle is a collection of points in a circle in the YZ plane

	std::vector<Point> circle2;
	for(int i = 0; i < this->resolution + 1; i++){
		circle2.push_back(circle[i].rotateY(angle));
	}

	for(int i = 0; i < this->resolution; i++){
		// draw line between each of the points on the circle
		this->addEdge(Edge(circle2[this->resolution-1], circle2[0]));
		for(int j = 1; j < this->resolution; j++){
			Edge v(circle2[j-1],circle2[j]);
			this->addEdge(v);
		}

		// draw a line between the two circles
		for(int j = 0; j < this->resolution; j++){
			Edge v(circle2[j], circle[j]);
			this->addEdge(v);
		}

		// copy circle2 into circle
		for(int j = 0; j < this->resolution; j++){
			circle[j] = circle2[j];
		}

		// rotate circle2 to next spot
		for(int j = 0; j < this->resolution; j++){
			circle2[j] = circle2[j].rotateY(angle);
		}
	}
}
