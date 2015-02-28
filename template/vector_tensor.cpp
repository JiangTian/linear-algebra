#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>

#include <assert.h>
#include "tensor.hpp"
#include "vector_tensor.hpp"
//#include "matrix_tensor.hpp"

using namespace std;
/*
template <typename T>
void Vector<T>::print() const {
  cout << "..printing from vector.." << endl;
  cout << " = [";
  for (int i = 0; i < total_length-1; i++)
    cout << array[i] << ",";
  cout << array[total_length-1] << "]" << endl;
}
*/
template <typename T>
T Vector<T>::dot(const Vector<T>& vec) const {
  assert(vec.getTotalLength() == total_length);
  T prod = 0.;
  for (int i = 0; i < total_length; i++)
    prod += array[i] * vec[i];
  return prod;
}
/*
Vector::operator Matrix() {
  Matrix m(total_length, 1);
  for (int i  = 0; i < total_length; i++)
    m[i] = array[i];
  return m;
  }*/
