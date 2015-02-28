#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <random>
#include <assert.h>

using namespace std;

//TODO: read files a, b, c. Store array Ai of problems in each category i, and compute ni's. Predetermine Ti's. Ti is the number of problems picked from the ith previous exam, constant for now.

int main() {
  const int T1(30), T2(28), T3(32); 
  const vector<int> n(7, 30); //foo
  vector<int> xs(7, -1);
  int t1 = T1 - n[0] - n[6];
  int t2 = T2 - n[1] - n[6];
  int t3 = T3 - n[2] - n[6];

  //keep picking x4 randomly from [0, n4] for now. Ideally with elimination for cases already tried.
  uniform_int_distribution<unsigned> u(0, n[3]);
  default_random_engine e;
  int times = 0;
  //calculate x4, x5, x6
  while (times < n[3] * 2) {
    int x4 = u(e);
    int xmin = max(0, t2 - x4);
    int xmax = min(n[4], T2 - x4);
    int ymin = max(0, t1 - x4);
    int ymax = min(n[5], T1 - x4);

    //start searching solutions from the bottom left corner of the box in xy plane
    if ((xmin + ymin <= T3) && (xmax + ymax >= t3)) {
	for (int x = xmin; x <= xmax; x++) {
	  for (int y = ymin; y <= ymax; y++) {
	    if ((x+y <= T3) && (x+y >= t3)) {
		xs[3] = x4;
		xs[4] = x;
		xs[5] = y;
	      } 		   
	  }
	}
	break;
      } else {
      ++times;
      continue;
    }
  }
  //calculate x1, x2, x3, x7
  int n17 = T1 - xs[3] - xs[5];
  int n27 = T2 - xs[3] - xs[4];
  int n37 = T3 - xs[4] - xs[5];
  uniform_int_distribution<unsigned> v(0, min(min(n17, n27), n37));
  xs[6] = v(e);
  xs[0] = n17 - xs[6];
  xs[1] = n27 - xs[6];
  xs[2] = n37 - xs[6];

  //check results are correct
  for (int i = 0; i < 7; i++)
    assert((xs[i] >= 0) && (xs[i] <= n[i]));
  assert(xs[0] + xs[3] + xs[5] + xs[6] == T1);
  assert(xs[1] + xs[3] + xs[4] + xs[6] == T2);
  assert(xs[2] + xs[4] + xs[5] + xs[6] == T3);

  //TODO: pick randomly xs[i-1] problems from Ai for each i, and print.
  for (int i = 0; i < 7; i++)
    cout << "Category" << i+1 << " = " << xs[i] << endl;
}
