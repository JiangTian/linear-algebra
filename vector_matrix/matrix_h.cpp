#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>

#include <assert.h>
#include "vector.hpp"

using namespace std;

class Matrix {
private:
  int row;
  int col;
  double* array;
  //Vector* matrix; 
  //how to do this with an array of Vectors?

public:
  Matrix(int i, int j): row(i), col(j) {
    assert(row > 0 && col > 0);
    //matrix = new Vector[row];
    array = new double[row * col];
    //for (int i = 0; i < row; i++) 
    //Vector matrix[i][col];
    this->fill(0.);
  }
  //default constructor Vector() {}, change "=" and delete.
  //add matrix[] returns a const Vector. 
  //faster way of doing transpose.
  // operator[](int i, int j) doesn't work since binary oveloaded blah..only one arg allowed

  void fill(double value) {
    for (int i = 0; i < row * col; i++) 
      array[i] = value;
  }
  /*
  //why doesn't this work?
    vector<int> size() const {
    // vector<int> v[2] = {row, col};
    return v;
    }*/

  int rows() const {
    return row;
  }

  int cols() const {
    return col;
  }

  double& operator()(int i, int j) {
    assert((i >= 0) && (i < row) && (j >= 0) && (j < col));
    return array[i*col + j];
  }

  const double& operator()(int i, int j) const {
    assert((i >= 0) && (i < row) && (j >= 0) && (j < col));
    return array[i*col + j];
  }
  
  const Vector operator[](int i) const {
    Vector row_i(col);
    for (int j = 0; j < col; j++)
      row_i[j] = array[i*col+j];
    return row_i;
  }

  void print() const {
    for (int i = 0; i < row; i++) 
      for (int j = 0; j < col; j++) 
	cout << "(" << i << ", " << j << ") = " << array[i*col+j] << endl;
  }
 
  Matrix operator+(Matrix& mat) {
    assert(mat.rows() == row && mat.cols() == col);
    Matrix sum(row, col);
    for (int i = 0; i < row; i++) 
      for (int j = 0; j < col; j++) 
	sum(i,j) = mat(i,j) + array[i*col+j];
    return sum;
  }

  void operator+=(Matrix& mat) {
    *this = *this + mat;
  }

  Matrix operator-(Matrix& mat) {
    assert(mat.rows() == row && mat.cols() == col);
    Matrix sub(row, col);
    for (int i = 0; i < row; i++) 
      for (int j = 0; j < col; j++) 
	sub(i,j) = array[i*col+j] - mat(i,j);
    return sub;
  }
 
  Matrix operator*(const double b) {
    Matrix prod(row, col);
    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++)
	prod(i,j) = array[i*col + j] * b;
    return prod;
  }
  
  Vector operator*(const Vector& vec) const {
    assert(col == vec.size());
    Vector prod(row);
    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++)
	prod[i] += array[i*col+j]*vec[j];
    return prod;
  }
  
  Matrix operator*(const Matrix& mat) const {
    assert(col == mat.rows());
    Matrix prod(row, mat.cols());
    for (int i  = 0; i < row; i++)
      for (int j = 0; j < mat.cols(); j++)
	for (int k = 0; k < col; k++)
	  prod(i,j) += array[i*col + k] * mat(k,j);
    return prod;
  }
  
  void transpose() {
    double m[row*col];
    for (int i = 0; i < row*col; i++)
      m[i] = array[i];
    for (int i  = 0; i < col; i++)
      for (int j  = 0; j < row; j++)
	array[i*row + j] = m[j*col + i];
    int a = row;
    row = col;
    col = a;
    }
}

int main() {
  Matrix x(3,2); //all ways to create a new class
  //cout << x.size() << endl;
  x(2,1) = 5;
  x(1,0) = 4;
  Matrix y(3,2); 
  y(2,1) = 6;
  y(1,0) = 5;
  cout << "y = " << endl;
  y.print();
  Matrix z(3,2);
  z = x+y;
  cout << "x+y = " << endl;
  z.print();
  z.transpose();
  cout << " z^T = " << endl;
  z.print();
  Matrix l(2,3);
  l.fill(1);
  Matrix k = x*l;
  cout << "matrix*matrix = " << endl;
  k.print();
  Vector::Vector g(3);
  g.fill(2);
  Vector::Vector m = l*g;
  cout << "matrix*vector = " << endl;
  m.print();
  return 0;
}
