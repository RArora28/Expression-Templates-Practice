//lazy evaluation

#include <bits/stdc++.h>
using namespace std;

struct vec;

struct BinaryAddExp {
	const vec &l;
	const vec &r;
	BinaryAddExp(const vec& l, const vec& r) : l(l) ,r(r) {}
};

struct vec {
	int len;
	float *v;

	vec(void) {}
	vec(float *x, int len) : v(x), len(len) {}

	//temporary structure to store 
	inline vec &operator=(const BinaryAddExp &X) {
		for(int i = 0; i < len; i++) {
			v[i] = X.l.v[i] + X.r.v[i];
		}
		//the destination is returned so no over head memory cost
		return *this;
	} 

};

inline BinaryAddExp operator+(const vec& x, const vec &y) {
	return BinaryAddExp(x, y);
}

const int n = 3;
int main() {
  float sa[n] = {1, 2, 3};
  float sb[n] = {2, 3, 4};
  float sc[n] = {3, 4, 5};
  vec A(sa, n), B(sb, n), C(sc, n);
  // run expression
  A = B + C;
  for (int i = 0; i < n; ++i) {
    printf("%d:%f==%f+%f\n", i, A.v[i], B.v[i], C.v[i]);
  }
  return 0;
}