#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define VAL(x) #x << " = " << (x) << "   "
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define CLR(x, a) memset(x, a, sizeof x)
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define FOR(i, n) for (int i = 0; i < (n); i ++)
#define X first
#define Y second
#define EPS 1e-8

const int MAXN = 5 * 1000 + 10, INF = 1e9;

int n, m;
int ex[MAXN], ey[MAXN], ew[MAXN], d[MAXN];

bool bellman(int start) {
	FOR(i, n) d[i] = INF;
	d[start] = 0;

	FOR(i, n - 1) FOR(j, m) {
		int x = ex[j], y = ey[j]; double w = tw[j];
		d[y] = min(d[y], d[x] + w);
	}

	// check if graph has a negative cycle
	FOR(i, m) {
		int x = ex[i], y = ey[i]; double w = tw[i];
		if (d[y] > d[x] + w) return false;
	}

	return true;
}


int main () {
	ios::sync_with_stdio(false);
	return 0;
}

