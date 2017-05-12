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
