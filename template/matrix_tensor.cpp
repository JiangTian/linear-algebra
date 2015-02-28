#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>

#include <assert.h>
#include "tensor.hpp"
#include "matrix_tensor.hpp"
#include "vector_tensor.hpp"

using namespace std;

Matrix::Matrix(const Vector& vec) {
  dim = 2;
  total_length = vec.getTotalLength();
  size = new int[2];
  row = size[0] = total_length;
  col = size[1] = 1;
  array = new double[total_length];
  for (int i = 0; i < total_length; i++)
    array[i] = vec[i];
}

void Matrix::print() const {
  cout << "..printing from matrix.." << endl;
  for (int i = 0; i < row; i++) 
    for (int j = 0; j < col; j++) 
      cout << "(" << i << ", " << j << ") = " << array[i*col+j] << endl;
}

Vector Matrix::operator*(const Vector& vec) const {
  assert(col == vec.getTotalLength());
  Vector prod(row);
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      prod[i] += array[i*col+j]*vec[j];
  return prod;
}
  
Matrix Matrix::operator*(const Matrix& mat) const {
  assert(col == mat.rows());
  Matrix prod(row, mat.cols());
  for (int i  = 0; i < row; i++)
    for (int j = 0; j < mat.cols(); j++)
      for (int k = 0; k < col; k++)
	prod(i,j) += array[i*col + k] * mat(k,j);
  return prod;
}
  
void Matrix::transpose() {
  double m[total_length];
  for (int i = 0; i < total_length; i++)
  m[i] = array[i];
  for (int i  = 0; i < col; i++)
    for (int j  = 0; j < row; j++)
      array[i*row + j] = m[j*col + i];
  int a = row;
  row = col;
  col = a;
}
