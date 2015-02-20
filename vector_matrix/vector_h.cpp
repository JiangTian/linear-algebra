#include <cstdio>
#include <cmath>
#include <iostream>
//#include <vector>
#include <cstdlib>

#include <assert.h>

using namespace std;

class Vector {
private:
  int n;
  double* array;

public: 
  Vector(int size): n(size) {
    assert(n > 0);
    array = new double[n];
    this->fill(0.);
  }

  void fill(double value) {
    for (int i = 0; i < n; i++)
      array[i] = value;
  }
  
  int size() const {
    return n;
  }

  double get(int i) const {
    assert(i >= 0 && i < n);
    return array[i];
  }
  
  void set(int i, double value) {
    assert(i >= 0 && i < n);
    array[i] = value;
  }

  Vector operator+(const Vector& vec) const {
    assert(vec.size() == n);
    Vector sum(n);
    for (int i = 0; i < n; i++)
      sum.set(i, vec.get(i) + array[i]);
    return sum;
  }

  Vector operator+(const double value) const {
    Vector sum(n);
    for (int i = 0; i < n; i++)
      sum.set(i, value + array[i]);
    return sum;
  }

  void operator+=(const Vector& vec) {
    *this = *this + vec;
  }

  Vector operator-(const Vector& vec) const {
    assert(vec.size() == n);
    Vector sub(n);
    for (int i = 0; i < n; i++)
      sub.set(i, array[i] - vec.get(i));
    return sub;
  }
  
  Vector operator*(const double value) const {
    Vector prod(n);
    for (int i = 0; i < n; i++)
      prod.set(i, value * array[i]);
    return prod;
  }
 
  Vector operator*(const Vector& vec) const {
    assert(vec.size() == n);
    Vector prod(n);
    for (int i = 0; i < n; i++)
      prod.set(i, array[i] * vec.get(i));
    return prod;
  }

  //which operator to use for dot product? operator.* doesn't work.
  double dot(const Vector& vec) const {
    assert(vec.size() == n);
    double prod = 0.;
    for (int i = 0; i < n; i++)
      prod += array[i] * vec.get(i);
    return prod;
  }

  Vector(const Vector& vec): n(vec.size()) {
    array = new double[n];
    for (int i = 0; i < n; i++)
      array[i] = vec.get(i);
  } //copy constructor

  Vector& operator=(const Vector& vec) {
    copy(vec);
    return *this;
  } // copy assignment

  void copy(const Vector& vec) {
    if (this != &vec) {
      delete[] array;
      array = new double[vec.size()]; 
      for (int i = 0; i < vec.size(); i++)
	array[i] = vec.get(i);
    }
  }

  void print() const {
    cout << " = [";
    for (int i = 0; i < n-1; i++)
      cout << array[i] << ",";
    cout << array[n-1] << "]" << endl;
  }

  ~Vector() { delete[] array;}
};


int main() {
  Vector x(1);
  //Vector y(x);
  Vector y(Vector(3));
  x.set(0,1);
  cout << "y";
  y.print();
  Vector a(3);
  a.set(0, 1.);
  a.set(1, 2.);
  a.set(2, 3.);
  Vector b(3);
  b.set(0, 4.);
  b.set(1, 5.);
  b.set(2, 6.);
  Vector c = a+b;
  cout << "c";
  c.print();
  a += b;
  cout << "a += b, a";
  a.print();
  double v = a.dot(b);
  cout << "a.b = " << v << endl;
  Vector prod = a*b;
  cout << "a*b";
  prod.print();
  return 0;
}
