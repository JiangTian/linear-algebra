#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>

#include <assert.h>
#include "tensor.hpp"

using namespace std;

Tensor::Tensor(int length): total_length(length) {
  assert(length > 0);
  dim = 1;
  array = new double[total_length];
  //int size[1] = {length};
  size = new int[1];
  size[0] = length;
  this->fill(0.);
}

Tensor::Tensor(int row, int col) {
  assert(row > 0 && col > 0);
  dim = 2;
  total_length = row*col;
  array = new double[total_length];
  //  int size[2] = {row, col};
  size = new int[2];
  size[0] = row;
  size[1] = col;
  this->fill(0.);
}

Tensor::Tensor(int dim1, int dim2, int dim3) {
  assert(dim1 > 0 && dim2 > 0 && dim3 > 0);
  dim = 3;
  total_length = dim1*dim2*dim3;
  array = new double[total_length];
  //int size[3] = {dim1, dim2, dim3};
  size = new int[3];
  size[0] = dim1;
  size[1] = dim2;
  size[2] = dim3;
  this->fill(0.);
}

Tensor::Tensor(int dim, int* dim_array): dim(dim), size(dim_array) {
  assert(dim > 0);
  size = new int[dim]; //pass just the pointer doesn't work!
  total_length = 1;
  for (int i  = 0; i < dim; i++) {
    size[i] = dim_array[i];
    total_length = total_length*size[i];    
  }
  array = new double[total_length];
  this->fill(0.);
}

void Tensor::fill(double value) {
  for (int i = 0; i < total_length; i++)
    array[i] = value;
}

double& Tensor::operator[](int i) {
  assert(i >= 0 && i < total_length);
  return array[i];
}

const double& Tensor::operator[](int i) const {
  assert(i >= 0 && i < total_length);
  return array[i];
}

Tensor Tensor::operator+(const Tensor& tsr) const {
  assert(dim == tsr.getDim());
  for (int i = 0; i < dim; i++)
    assert(size[i] == tsr.getSize()[i]);
  Tensor sum(dim, size); 
  for (int i = 0; i < total_length; i++)
    sum[i] = array[i] + tsr[i];
  return sum;
}

Tensor Tensor::operator+(const double b) const {
  Tensor sum(dim, size); 
  for (int i = 0; i < total_length; i++)
    sum[i] = array[i] + b;
  return sum;
}

Tensor Tensor::operator-(const Tensor& tsr) const {
  assert(dim == tsr.getDim());
  for (int i = 0; i < dim; i++)
    assert(size[i] == tsr.getSize()[i]);
  Tensor sum(dim, size); 
  for (int i = 0; i < total_length; i++)
    sum[i] = array[i] - tsr[i];
  return sum;
}

Tensor Tensor::operator*(const Tensor& tsr) const {
  assert(dim == tsr.getDim());
  for (int i = 0; i < dim; i++)
    assert(size[i] == tsr.getSize()[i]);
  Tensor prod(dim, size); 
  for (int i = 0; i < total_length; i++)
    prod[i] = array[i] * tsr[i];
  return prod;
}

Tensor Tensor::operator*(const double b) const {
  Tensor prod(dim, size); 
  for (int i = 0; i < total_length; i++)
    prod[i] = array[i] * b;
  return prod;
}

Tensor& Tensor::operator+=(const Tensor& tsr) {
  assert(dim == tsr.getDim());
  for (int i = 0; i < dim; i++)
    assert(size[i] == tsr.getSize()[i]);
  *this = *this + tsr;
  return *this;
}

Tensor::Tensor(const Tensor& tsr) {
  dim = tsr.getDim();
  size = tsr.getSize();
  total_length = tsr.getTotalLength();
  array = new double[total_length];
  for (int i = 0; i < total_length; i++)
    array[i] = tsr[i];
}
  
Tensor& Tensor::operator=(const Tensor& tsr) {
  if (this != &tsr) {
    if (dim > 0)
      delete[] size;
      delete[] array; // doesn't delete the pointer? 
    total_length = tsr.getTotalLength();
    dim = tsr.getDim();
    //size = tsr.getSize();
    size = new int[dim];
    for (int i = 0; i < dim; i++)
      size[i] = tsr.getSize()[i];
    array = new double[total_length]; 
    for (int i = 0; i < total_length; i++)
      array[i] = tsr[i];
  }
    return *this;
}
