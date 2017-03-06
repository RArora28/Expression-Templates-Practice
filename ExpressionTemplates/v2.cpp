//lazy evaluation

#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Vec;

template <class T>
struct BinaryAddExp {
	const Vec<T> &l;
	const Vec<T> &r;
	BinaryAddExp(const Vec<T> &l, const Vec<T> &r) : l(l) ,r(r) {}
};

template<class T>
struct Vec{
	int len;
	T *v;

	Vec(void) {}
	Vec(T *x, int len) : v(x), len(len) {}

	//temporary structure to store 
	inline Vec &operator=(const BinaryAddExp<T> &X) {
		for(int i = 0; i < len; i++) {
			v[i] = X.l.v[i] + X.r.v[i];
		}
		//the destination is returned so no over head memory cost
		return *this;
	} 

};

template <class T>
inline BinaryAddExp<T> operator+(const Vec<T> &x, const Vec<T> &y) {
	return BinaryAddExp<T>(x, y);
}

const int n = 3;
int main() {
  int sa[n] = {1, 2, 3};
  int sb[n] = {2, 3, 4};
  int sc[n] = {3, 4, 5};
  Vec<int> A(sa, n), B(sb, n), C(sc, n);
  // run expression
  A = B + C;
  for (int i = 0; i < n; ++i) {
    printf("%d:%d==%d+%d\n", i, A.v[i], B.v[i], C.v[i]);
  }
  return 0;
}