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

bool mark[MAXN], ans[MAXM];
int depth[MAXN];
vector<pii> adj[MAXN], tmp_adj[MAXN];

int dfs(int x, int len, int par) {
	int mn = INF;
	depth[x] = len;
	mark[x] = true;
	for (int i = 0; i < SZ(adj[x]); i ++) {
		int v = adj[x][i].X, idx = adj[x][i].Y;
		if (mark[v] && idx != par) {
			ans[idx] = 1;
			mn = min(mn, depth[v]);
		}
	}
	for (int i = 0; i < SZ(adj[x]); i ++) {
		int v = adj[x][i].X, idx = adj[x][i].Y;
		if (mark[v]) continue;
		int cur = dfs(v, len + 1, idx);
		if (cur <= len) {
			ans[idx] = 1;
		}
		mn = min(mn, cur);
	}
	return mn;
}

int par[MAXN];

int father(int x) {
	return par[x] == -1 ? x : par[x] = father(par[x]);
}

void merge(int x, int y) {
	x = father(x);
	y = father(y);
	if (x != y) par[y] = x;
}

pair<pii, pii> e[MAXM];

int main () {
	ios::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i ++) {
		int x, y, w; cin >> x >> y >> w; x--, y--;
		e[i] = mp(mp(w, i), mp(x, y));
	}

	for (int i = 0; i < n; i ++) par[i] = -1;

	sort(e, e + m);

	for (int i = 0; i < m; i ++) {
		vector<pair<pii, pii> > cur;
		int idx = i;
		while (idx < m && e[idx].X.X == e[i].X.X) {
			cur.pb(e[idx]);
			idx ++;
		}

		for (int j = 0; j < n; j ++) adj[j].clear();
		for (int j = 0; j < SZ(cur); j ++) {
			int x = father(cur[j].Y.X), y = father(cur[j].Y.Y), idx = cur[j].X.Y;
			if (x == y) { 
				ans[idx] = 1;
				continue;
			}
			adj[x].pb(mp(y, idx));
			adj[y].pb(mp(x, idx));
		}

		for (int j = 0; j < n; j ++) mark[j] = false, depth[j] = 0;
		for (int j = 0; j < n; j ++) if (!mark[j])
			dfs(j, 0, -1);
		
		for (int j = 0; j < SZ(cur); j ++) {
			int x = cur[j].Y.X, y = cur[j].Y.Y;
			merge(x, y);
		}

		i = idx - 1;
	}

	int ans_cnt = 0, ans_sum = 0;
	for (int i = 0; i < m; i ++) if (!ans[e[i].X.Y]) {
		ans_cnt ++;
		ans_sum += e[i].X.X;
	}

	cout << ans_cnt << ' ' << ans_sum << endl;
	return 0;
}

