#include <iostream>
#include <complex>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

const ld EPS = 1e-9;

ld operator ^(const point &a, const point &b) {
	return imag(a * conj(b));
}

ld operator |(const point &a, const point &b) {
	return real(a * conj(b));
}

bool in_between(const point &a, const point &b, const point &c) {
	if(norm(a - c) <= 2 * EPS || norm(b - c) <= 2 * EPS)
		return true;
	ld t = norm(a - b);
	return (abs((a - b) ^ (c - b)) <= EPS) && (norm(a - c) <= t) && (norm(b - c) <= t);
}

point intersection(const point &a, const point &b, const point &c, const point &d) {
	if(abs((b - a) ^ (d - c)) <= EPS) {
		if(in_between(a, b, c))
			return c;
		if(in_between(a, b, d))
			return d;
		//if(in_between(c, d, a))
			return a;
	}
	ld s = ((c - a) ^ (d - c)) / ((b - a) ^ (d - c));
	return a + s * (b - a);
}

int main() {
	ios::sync_with_stdio(false);
	ld ta, tb;
	point a[4];
	for(int i = 0;i < 4;++i)
		cin >> ta >> tb, a[i] = point(ta, tb);
	point b = intersection(a[0], a[1], a[2], a[3]);
	if(in_between(a[0], a[1], b))
		cout << b << endl;
	else
		cout << "No" << endl;
	return 0;
}
