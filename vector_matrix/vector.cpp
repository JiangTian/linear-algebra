#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>

#include <assert.h>
#include "vector.hpp"

using namespace std;

//do I need "Vector::" if in one member function I need to use another member function?

Vector::Vector() {
  int n = 0;
  double* array;
}

Vector::Vector(int size): n(size) {
  assert(n > 0);
  array = new double[n];
  this->fill(0.);
}

void Vector::fill(double value) {
  for (int i = 0; i < n; i++)
    array[i] = value;
}

double& Vector::operator[](int i) {
  assert(i >= 0 && i < n);
  return array[i];
}

const double& Vector::operator[](int i) const {
  assert(i >= 0 && i < n);
  return array[i];
}

Vector Vector::operator+(const Vector& vec) const {
  assert(vec.size() == n);
  Vector sum(n);
  for (int i = 0; i < n; i++)
    sum[i] = vec[i] + array[i];
  return sum;
}

Vector Vector::operator+(const double value) const {
  Vector sum(n);
  for (int i = 0; i < n; i++)
    sum[i] = value + array[i];
  return sum;
}

Vector& Vector::operator+=(const Vector& vec) {
  assert(vec.size() == n);
  *this = *this + vec;
  return *this;
}

Vector Vector::operator-(const Vector& vec) const {
  assert(vec.size() == n);
  Vector sub(n);
  for (int i = 0; i < n; i++)
    sub[i] = array[i] - vec[i];
  return sub;
}
  
Vector Vector::operator*(const double value) const {
  Vector prod(n);
  for (int i = 0; i < n; i++)
    prod[i] = value * array[i];
  return prod;
}
 
Vector Vector::operator*(const Vector& vec) const {
  assert(vec.size() == n);
  Vector prod(n);
  for (int i = 0; i < n; i++)
    prod[i] = array[i] * vec[i];
  return prod;
}

double Vector::dot(const Vector& vec) const {
  assert(vec.size() == n);
  double prod = 0.;
  for (int i = 0; i < n; i++)
    prod += array[i] * vec[i];
  return prod;
}

Vector::Vector(const Vector& vec): n(vec.size()) {
  array = new double[n];
  for (int i = 0; i < n; i++)
    array[i] = vec[i];
} //copy constructor

Vector& Vector::operator=(const Vector& vec) {
  if (this != &vec) {
    if (n > 0)
      delete[] array; // doesn't delete the pointer? 
    n = vec.size();
    array = new double[n]; 
    for (int i = 0; i < n; i++)
      array[i] = vec[i];
  }
  return *this;
} // copy assignment

void Vector::print() const {
  cout << " = [";
  for (int i = 0; i < n-1; i++)
    cout << array[i] << ",";
  cout << array[n-1] << "]" << endl;
}

