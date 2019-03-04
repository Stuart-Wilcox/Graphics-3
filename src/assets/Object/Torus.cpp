#include <cstdio>
#include <cmath>
#include <vector>
#include "Torus.hpp"


Torus::Torus(double innerRadius, double outerRadius){
	this->resolution = 36;
	const double angle = 360.0 / this->resolution;

	std::vector<Point> circle1;
	Point p(0.0, 0.0, innerRadius);
	circle1.push_back(p);

	for(int i = 1; i < this->resolution; i++){
		p = p.rotateX(angle);
		circle1.push_back(p);
	}

	// circle1 is now a circle of radius given by argument, in the YZ plane centered at the origin
	// must rotate it about the Y axis 90 degress to put it in the XY plane
	// translate it outerRadius units along the X axis
	for(int i = 0; i < this->resolution; i++){
		circle1[i] = circle1[i].rotateY(90.0);
		circle1[i].x += outerRadius;
	}

	// rotate circle1 points about y-axis, connecting each time
	std::vector<Point> circle2;
	for(int i = 0; i < this->resolution; i++){
		circle2.push_back(circle1[i].rotateY(angle));
	}

	for(int i = 0; i < this->resolution; i++){
		// conect previous circle with current
		for(int j = 0; j < this->resolution; j++){
			Edge v(circle1[j], circle2[j]);
			this->addEdge(v);
		}

		// connect the circle points with one another
		this->addEdge(Edge(circle2[0], circle2[this->resolution-1]));
		for(int j = 1; j < this->resolution; j++){
			Edge v(circle2[j-1], circle2[j]);
			this->addEdge(v);
		}

		// copy circle2 into circle1
		for(int j = 0; j < this->resolution; j++){
			circle1[j] = circle2[j];
		}

		// rotate circle2 about y-axis
		for(int j = 0; j < this->resolution; j++){
			circle2[j] = circle2[j].rotateY(angle);
		}
	}

}
