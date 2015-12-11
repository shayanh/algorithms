#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define CLR(x, a) memset(x, a, sizeof x)
#define VAL(x) #x << " = " << (x) << "   "
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define FOR(i, n) for (int i = 0; i < (n); ++ i)
#define X first
#define Y second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int MAXN = 100 * 1000 + 10, MAXL = 20;

vector<int> adj[MAXN];
int par[MAXN][MAXL], h[MAXN];
bool mark[MAXN];

void dfs(int x) {
	mark[x] = true;
	for (int i = 0; i < SZ(adj[x]); i ++) {
		int v = adj[x][i];
		if (!mark[v]) {
			par[v][0] = x, h[v] = h[x] + 1;
			dfs(v);
		}
	}
}

int get_parent(int x, int k) {
	for (int i = 0; i < MAXL; i ++)
		if ((1 << i) & k) x = par[x][i];
	return x;
}

int lca(int x, int y) {
	if (h[y] > h[x]) swap(x, y);	
	x = get_parent(x, h[x] - h[y]);

	if (x == y) return x;

	for (int i = MAXL - 1; i >= 0; i--)
		if (par[x][i] != par[y][i])
			x = par[x][i], y = par[y][i];
	return par[x][0];
}

int main () {
	ios::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	par[0][0] = -1;
	dfs(0);
	for (int i = 1; i < MAXL; i ++)
		for (int j = 0; j < n; j ++)
			par[j][i] = par[par[j][i - 1]][i - 1];

	return 0;
}

