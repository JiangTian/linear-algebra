#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>

#include <assert.h>
#include "tensor.hpp"

using namespace std;
/*
template <typename T>
Tensor<T>::Tensor(int length): total_length(length) {
  assert(length > 0);
  dim = 1;
  array = new T[total_length];
  size = new int[1];
  size[0] = length;
  this->fill((T)0);
}
template <typename T>
Tensor<T>::Tensor(int row, int col) {
  assert(row > 0 && col > 0);
  dim = 2;
  total_length = row*col;
  array = new T[total_length];
  size = new int[2];
  size[0] = row;
  size[1] = col;
  this->fill((T)0);
  }*/
template <typename T>
Tensor<T>::Tensor(int dim1, int dim2, int dim3) {
  assert(dim1 > 0 && dim2 > 0 && dim3 > 0);
  dim = 3;
  total_length = dim1*dim2*dim3;
  array = new T[total_length];
  size = new int[3];
  size[0] = dim1;
  size[1] = dim2;
  size[2] = dim3;
  this->fill((T)0);
}
template <typename T>
Tensor<T>::Tensor(int dim, int* dim_array): dim(dim), size(dim_array) {
  assert(dim > 0);
  size = new int[dim];
  total_length = 1;
  for (int i  = 0; i < dim; i++) {
    size[i] = dim_array[i];
    total_length = total_length*size[i];    
  }
  array = new T[total_length];
  this->fill((T)0);
}
/*
template <typename T>
void Tensor<T>::fill(T value) {
  for (int i = 0; i < total_length; i++)
    array[i] = value;
    }*/

template <typename T>
void Tensor<T>::print(int* index) const {
  for (int i = 0; i < dim; i++)
    assert(size[i] > index[i]);
  cout << "[";
    for (int i  = 0; i < dim-1; i++)
      cout << index[i] << ", "; 
    cout << index[dim-1] << "] = ";
    int array_index = 0;
    for (int i = 0; i < dim; i++) {
      int subLen = 1;
      for (int j = 0; j <= i; j++)
	subLen = subLen*size[j];  
      array_index += index[i]*total_length/subLen;
    }
    assert(array_index < total_length);
    cout << array[array_index] << "; ";
}
/*
template <typename T>
void Tensor<T>::print() const {
  cout << "..printing from tensor.." << endl;
  if (dim == 0) {
    cout << "Print: tensor empty!" << endl;
  } else {
    int* index = new int[dim]();
    while (true) {
    print(index);
    index[dim-1] += 1;
    for (int i = dim-1; i > 0; i--)
      if (index[i] == size[i]) {
	index[i-1] += 1;
	index[i] = 0;
      }
    if (index[0] == size[0])
      break;
    }
  }
  cout << endl;
  }*/

template <typename T>
T& Tensor<T>::operator[](int i) {
  assert(i >= 0 && i < total_length);
  return array[i];
}
template <typename T>
const T& Tensor<T>::operator[](int i) const {
  assert(i >= 0 && i < total_length);
  return array[i];
}
template <typename T>
Tensor<T> Tensor<T>::operator+(const Tensor<T>& tsr) const {
  assert(dim == tsr.getDim());
  for (int i = 0; i < dim; i++)
    assert(size[i] == tsr.getSize()[i]);
  Tensor<T> sum(dim, size); 
  for (int i = 0; i < total_length; i++)
    sum[i] = array[i] + tsr[i];
  return sum;
}
template <typename T>
Tensor<T> Tensor<T>::operator+(const double b) const {
  Tensor<T> sum(dim, size); 
  for (int i = 0; i < total_length; i++)
    sum[i] = array[i] + b;
  return sum;
}
template <typename T>
Tensor<T> Tensor<T>::operator-(const Tensor<T>& tsr) const {
  assert(dim == tsr.getDim());
  for (int i = 0; i < dim; i++)
    assert(size[i] == tsr.getSize()[i]);
  Tensor<T> sum(dim, size); 
  for (int i = 0; i < total_length; i++)
    sum[i] = array[i] - tsr[i];
  return sum;
}
template <typename T>
Tensor<T> Tensor<T>::operator*(const Tensor<T>& tsr) const {
  assert(dim == tsr.getDim());
  for (int i = 0; i < dim; i++)
    assert(size[i] == tsr.getSize()[i]);
  Tensor<T> prod(dim, size); 
  for (int i = 0; i < total_length; i++)
    prod[i] = array[i] * tsr[i];
  return prod;
}
template <typename T>
Tensor<T> Tensor<T>::operator*(const double b) const {
  Tensor<T> prod(dim, size); 
  for (int i = 0; i < total_length; i++)
    prod[i] = array[i] * b;
  return prod;
}
template <typename T>
Tensor<T>& Tensor<T>::operator+=(const Tensor<T>& tsr) {
  assert(dim == tsr.getDim());
  for (int i = 0; i < dim; i++)
    assert(size[i] == tsr.getSize()[i]);
  *this = *this + tsr;
  return *this;
}
template <typename T>
Tensor<T>::Tensor(const Tensor<T>& tsr) {
  dim = tsr.getDim();
  size = new int[dim];
  for (int i = 0; i < dim; i++)
    size[i] = tsr.getSize()[i];
  total_length = tsr.getTotalLength();
  array = new T[total_length];
  for (int i = 0; i < total_length; i++)
    array[i] = tsr[i];
}
template <typename T>
Tensor<T>& Tensor<T>::operator=(const Tensor<T>& tsr) {
  if (this != &tsr) {
    delete[] size;
    delete[] array; 
    total_length = tsr.getTotalLength();
    dim = tsr.getDim();
    size = new int[dim];
    for (int i = 0; i < dim; i++)
      size[i] = tsr.getSize()[i];
    array = new T[total_length]; 
    for (int i = 0; i < total_length; i++)
      array[i] = tsr[i];
  }
    return *this;
}
