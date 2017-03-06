//the most naive solution to add two vectors

#include <bits/stdc++.h>
using namespace std;

struct Vec {
	int len;
	float *v;
	Vec(int len) : len(len) {
		v = new float[len];
	}
	Vec(const Vec& x) : len(x.len) {
		v = new float[len];
		memcpy(v, x.v, sizeof(float)*len);
	}
	~Vec(void) {
		delete [] v;
	} 
};

inline Vec operator+(const Vec& x, const Vec& y) {
	assert(x.len == y.len);
	Vec res(x.len);
	for(int i = 0; i < x.len; i++) 
		res.v[i] = x.v[i] + y.v[i];
	return res;
}

int main() {

	Vec x(5), y(5);
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
	
	Vec z = x + y;

	for(int i = 0; i < 5; i++) {
		cout << x.v[i] << '+' << y.v[i] << '=' << z.v[i] << endl;
	}
	return 0;
}
