//uva.onlinejudge.org : 681
#include <complex>
typedef long long ld;
typedef complex <ld> point;
#define X real()
#define Y imag()
#define Size(x) (int)(x).size()

const ld EPS = 1e-12;
vector <point> vl;//convex hull vector
point p[N], O;//

ld operator ^(const point &a, const point &b) {
	return imag(a * conj(b));
}

ld operator |(const point &a, const point &b) {
	return real(a * conj(b));
}

bool cmp(const point &a, const point &b) {
	return (((a - O) ^ (b - O)) < (ld)0) || (((a - O) ^ (b - O)) == 0 && norm(a - O) < norm(b - O));
}

inline bool chk(const point &a, const point &b, const point &c) {
	return (((b - c) ^ (a - c)) >= (ld)0);
}

void find_hull(int n) {
	int ind = 0;
	for(int i = 0;i < n;++i)
		if(p[i].Y < p[ind].Y || (p[i].Y == p[ind].Y && p[i].X < p[ind].X))
			ind = i;
	swap(p[0], p[ind]);
	O = p[0];
	sort(p + 1, p + n, cmp);
	vl.push_back(p[0]);
	for(int i = 1;i < n;++i) {
		while(Size(vl) > 1 && chk(p[i], vl.back(), vl[Size(vl) - 2]))
			vl.pop_back();
		vl.push_back(p[i]);
	}
	while(Size(vl) > 1 && chk(p[0], vl.back(), vl[Size(vl) - 2]))
		vl.pop_back();
}
