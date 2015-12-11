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
#define FOR(i, n) for (int i = 0; i < (n); i ++)
#define X first
#define Y second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int MAXN = 100 * 1000 + 10;

int backEdge[MAXN], h[MAXN], mark[MAXN], cut[MAXN];
vector<pii> adj[MAXN];

void dfs(int x, int par, int len) {
	mark[x] = true, backEdge[x] = 1e9, h[x] = len;

	for (int i = 0; i < SZ(adj[x]); i ++) {
		int v = adj[x][i].X, idx = adj[x][i].Y;
		if (mark[v] && v != par) backEdge[x] = min(backEdge[x], h[v]);
		else if (!mark[v]) {
			dfs(v, x, len + 1);
			int tmp = backEdge[v];
			if (tmp > h[x]) cut[idx] = true;
			backEdge[x] = min(backEdge[x], tmp);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i ++) {
		int x, y;
		cin >> x >> y; x --, y --;
		adj[x].pb(mp(y, i));
		adj[y].pb(mp(x, i));
	}

	for (int i = 0; i < n; i ++)
		if (!mark[i]) dfs(i, -1, 0);
	
	vector<int> ans;
	for (int i = 0; i < m; i ++) if (cut[i]) ans.pb(i + 1);

	cout << SZ(ans) << endl;
	for (int i = 0; i < SZ(ans); i ++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
} 
