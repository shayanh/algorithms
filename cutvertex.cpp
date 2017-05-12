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
