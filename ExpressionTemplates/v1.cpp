//the most naive solution to add two vectors

#include <bits/stdc++.h>
using namespace std;

template<class T>
struct  Vec {
	//public:
	int len;
	T *v;
	//initialise the size of the vector
	Vec(int len) : len(len) {
		v = new T[len];
	}
	//copy constructor
	Vec(const Vec<T>& x) : len(x.len) {
		v = new T[len];
		memcpy(v, x.v, sizeof(T)*len);
	}
	//destructor
	~Vec(void) {
		delete [] v;
	}
	// friend Vec operator+(const Vec &x, const Vec &y);
};

//defines sum of 2 vector
template<class T>
inline Vec<T> operator+(const Vec<T> &x, const Vec<T> &y) {
	assert(x.len == y.len);
	Vec<T> res(x.len);
	for(int i = 0; i < x.len; i++) 
		res.v[i] = x.v[i] + y.v[i];
	return res;
}

int main() {

	Vec<int> x(5), y(5);
	x.v[0] = 0;
	x.v[1] = 1;
	x.v[2] = 2;
	x.v[3] = 3;
	x.v[4] = 4;
	y.v[0] = 5;
	y.v[1] = 6;
	y.v[2] = 7;
	y.v[3] = 8;
	y.v[4] = 9;
	
	Vec<int> z = x + y;

	for(int i = 0; i < 5; i++) {
		cout << x.v[i] << '+' << y.v[i] << '=' << z.v[i] << endl;
	}
	return 0;
}
