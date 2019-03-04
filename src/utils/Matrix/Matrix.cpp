#include <cstdio>
#include "Matrix.hpp"

Matrix::Matrix(int n, int m){
	this->n = n;
	this->m = m;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			this->matrix[i][j] = 0.0;
		}
	}
}

Matrix::Matrix(int n, int m, std::vector<std::vector<double> > init){
	this->n = n;
	this->m = m;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			this->matrix[i][j] = init[i][j];
		}
	}
}

void Matrix::print(){
	printf("Matrix\n");
	for(int i = 0; i < this->n; i++){
		printf("\t|");
		for(int j = 0; j < this->m; j++){
			printf("\t%f", this->matrix[i][j]);
		}
		printf("|\n");
	}
}

double* Matrix::operator[](int index){
	return this->matrix[index];
}

Matrix Matrix::operator+(Matrix& rhs){
	// size must be same in order to add
	if(this->n == rhs.n && this->m == rhs.m){
		Matrix newMatrix(this->n, this->m);

		for(int i = 0; i < this->n; i++){
			for(int j = 0; j < this->m; j++){
				newMatrix[i][j] = this->matrix[i][j] + rhs[i][j];
			}
		}

		return newMatrix;
	}

	return Matrix(0,0);
}

Matrix Matrix::operator-(Matrix& rhs){
	// size must be the same in order to subtract
	if(this->n == rhs.n && this->m == rhs.m){
		Matrix newMatrix(this->n, this->m);

		for(int i = 0; i < this->n; i++){
			for(int j = 0; j < this->m; j++){
				newMatrix[i][j] = this->matrix[i][j] - rhs[i][j];
			}
		}

		return newMatrix;
	}

	return Matrix(0,0);
}

Matrix Matrix::operator*(Matrix& rhs){
	// size must match to multiply
	if(this->m == rhs.n){
		Matrix newMatrix(this->n, rhs.m);

		for(int i = 0; i < newMatrix.n; i++){
			for(int j = 0; j < newMatrix.m; j++){
				for(int k = 0; k < rhs.n; k++){
					newMatrix[i][j] += this->matrix[i][k] * rhs[k][j];
				}
			}
		}

		return newMatrix;
	}

	return Matrix(0,0);
}
