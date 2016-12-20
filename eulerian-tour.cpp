void euler(int x) {
	for (int i = 0; i < SZ(graph[x]); i ++) {
		int v = graph[x][i];
		if (!vis[x][v]) {
			vis[x][v] = vis[v][x] = true;
			euler(v);
		}
	}
	tour.pb(x);
}