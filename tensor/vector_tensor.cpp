#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>

#include <assert.h>
#include "tensor.hpp"
#include "vector_tensor.hpp"

using namespace std;

void Vector::print() const {
  cout << " = [";
  for (int i = 0; i < total_length-1; i++)
    cout << array[i] << ",";
  cout << array[total_length-1] << "]" << endl;
}

double Vector::dot(const Vector& vec) const {
  assert(vec.getTotalLength() == total_length);
  double prod = 0.;
  for (int i = 0; i < total_length; i++)
    prod += array[i] * vec[i];
  return prod;
}
