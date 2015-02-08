#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
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

  Vector add(Vector vec) const {
    assert(vec.size() == n);
    Vector sum(n);
    for (int i = 0; i < n; i++)
      sum.set(i, vec.get(i) + array[i]);
    // why sum.get(i) is not assignable? Is the reason sum.array private?
    return sum;
  }

  Vector add(const double value) const {
    Vector sum(n);
    for (int i = 0; i < n; i++)
      sum.set(i, value + array[i]);
    return sum;
  }

  Vector sub(Vector vec) const {
    assert(vec.size() == n);
    Vector sub(n);
    for (int i = 0; i < n; i++)
      sub.set(i, array[i] - vec.get(i));
    return sub;
  }
  
  Vector mul(const double value) const {
    Vector prod(n);
    for (int i = 0; i < n; i++)
      prod.set(i, value * array[i]);
    return prod;
  }
 
  Vector cmul(Vector vec) const {
    assert(vec.size() == n);
    Vector prod(n);
    for (int i = 0; i < n; i++)
      prod.set(i, array[i] * vec.get(i));
    return prod;
  }

  double dot(Vector vec) const {
    assert(vec.size() == n);
    double prod = 0.;
    for (int i = 0; i < n; i++)
      prod += array[i] * vec.get(i);
    return prod;
  }
};

int main() {
  Vector a(3);
  a.set(0, 1.);
  a.set(1, 2.);
  a.set(2, 3.);//. necessary?
  Vector b(3);
  b.set(0, 4.);
  b.set(1, 5.);
  b.set(2, 6.);
  Vector c = a.add(b);
  cout << "c = [" << c.get(0) << ", " << c.get(1) << ", " << c.get(2) << "]" << endl;
  double v = a.dot(b);
  cout << "a.b = " << v << endl;
  Vector prod = a.sub(b);
  cout << "a*b = [" << prod.get(0) << ", " << prod.get(1) << ", " << prod.get(2) << "]" << endl;
}
