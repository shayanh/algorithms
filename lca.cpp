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
	par[0][0] = -1;
	dfs(0);
	for (int i = 1; i < MAXL; i ++)
		for (int j = 0; j < n; j ++)
			par[j][i] = par[par[j][i - 1]][i - 1];
}

