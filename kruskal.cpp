#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define VAL(x) #x << " = " << x << "   "
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define CLR(x, a) memset(x, a, sizeof x)
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define FOR(i, n) for (int i = 0; i < (n); i ++)
#define X first
#define Y second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 600, MAXM = 50 * 1000 + 10, INF = 1e9;

int par[MAXN];

int father(int x) {
	return par[x] == -1 ? x : par[x] = father(par[x]);
}

void merge(int x, int y) {
	x = father(x);
	y = father(y);
	if (x != y) par[y] = x;
}

pair<int, pii> e[MAXM];

int main () {
	ios::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i ++) {
		int x, y, w; cin >> x >> y >> w; x--, y--;
		e[i] = mp(w, mp(x, y));
	}

	for (int i = 0; i < n; i ++) par[i] = -1;

	sort(e, e + m);

	int ans = 0;
	for (int i = 0; i < m; i ++) {
		int x = father(e[i].Y.X), y = father(e[i].Y.Y), w = e[i].X;
		if (x == y) continue;

		merge(x, y);
		ans += w;
	}

	cout << ans << endl;
	return 0;
}

