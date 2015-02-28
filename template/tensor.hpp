#ifndef TENSOR_H
#define TENSOR_H

#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>

#include <assert.h>

using namespace std;

template <typename T>
class Tensor {
protected:
  int dim;
  int* size;
  int total_length;
  T* array;

public:
  //constructors
  Tensor(): dim(0), total_length(0) {
    size = new int[0];
    array = new T[0];
}; 
  Tensor(int length) {
    assert(length > 0);
    dim = 1;
    array = new T[total_length];
    size = new int[1];
    size[0] = length;
    this->fill((T)0);
  };
  Tensor(int row, int col) {
    assert(row > 0 && col > 0);
    dim = 2;
    total_length = row*col;
    array = new T[total_length];
    size = new int[2];
    size[0] = row;
    size[1] = col;
    this->fill((T)0);
  };
  Tensor(int dim1, int dim2, int dim3);
  Tensor(int dim, int* dim_array);

  //utility functions
  void fill(T value) {
    for (int i = 0; i < total_length; i++)
      array[i] = value;
  };
  int* getSize() const {return size;};
  int getDim() const {return dim;};
  int getTotalLength() const {return total_length;};
  void print(int*) const;
  //virtual void print() const;
  T& operator[](int);
  const T& operator[](int) const;

  //arithmetic operations
  Tensor operator+(const Tensor&) const;
  //template <typename It>
  Tensor operator+(const double) const;
  Tensor operator-(const Tensor&) const;
  Tensor& operator+=(const Tensor&);
  Tensor operator*(const double) const;
  Tensor operator*(const Tensor&) const;

  //copy constructor
  Tensor(const Tensor&);
  //copy assignment
  Tensor& operator=(const Tensor&);
  //destructor
  //virtual
  virtual ~Tensor() {
    std::cout << "destructing Tensor" << std::endl;
    delete[] size;
    delete[] array;
  }
};

#endif
