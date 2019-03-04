/* Simple test program to confirm functionality of utils */
#include <cstdio>
#include "utils/Matrix/Matrix.hpp"
#include "assets/Camera/Camera.hpp"
#include "assets/Point/Point.hpp"

void matrix();
void camera();

int main(){
	// uncomment a section to inspect it working
	// matrix();
	// camera();
}

void matrix(){
	Matrix m1(2,3);
	Matrix m2(3,2);

	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[0][2] = 3;
	m1[1][0] = 4;
	m1[1][1] = 5;
	m1[1][2] = 6;

	m2[0][0] = 7;
	m2[0][1] = 8;
	m2[1][0] = 9;
	m2[1][1] = 10;
	m2[2][0] = 11;
	m2[2][1] = 12;

	m1.print();
	m2.print();

	// Matrix m3 = m1 + m2;
	// m3.print();

	Matrix m4 = m1 * m2;
	m4.print();
}

void camera(){
	Camera camera(Point(0.0,10.0,-30.0), 0.0, 0.0, 0.0);
}
