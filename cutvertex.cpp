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

bool mark[MAXN], ans[MAXN];
int edge[MAXN], h[MAXN];
vector<int> adj[MAXN];

void dfs(int x, int par, int dep) {
	mark[x] = true; h[x] = dep;
	edge[x] = 1e9;

	bool check = false;
	int cnt = 0;
	for (int i = 0; i < SZ(adj[x]); i ++) {
		int v = adj[x][i]; if (v == par) continue;
		if (mark[v]) edge[x] = min(edge[x], h[v]);
		else {
			cnt ++;
			dfs(v, x, dep + 1);
			if (edge[v] >= dep) check = true;
			edge[x] = min(edge[x], edge[v]);
		}
	}

	ans[x] = check;
	if (par == -1 && cnt < 2) ans[x] = false;
}

int main() {
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i ++) {
		int x, y;
		cin >> x >> y; x--, y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	for (int i = 0; i < n; i ++)
		if (!mark[i]) dfs(i, -1, 0);
	
	vector<int> res;
	for (int i = 0; i < n; i ++)
		if (ans[i]) res.pb(i + 1);
	cout << SZ(res) << endl;
	for (int i = 0; i < SZ(res); i ++)
		cout << res[i] << ' ';
	cout << endl;
	return 0;
} 
