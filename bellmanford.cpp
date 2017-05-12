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
