const int MAXN = 600, MAXM = 50 * 1000 + 10, INF = 1e9;

int par[MAXN];
pair <int, pii> e[MAXN];

int father(int x) {
	return par[x] == -1 ? x : par[x] = father(par[x]);
}

bool merge(int x, int y) {
	x = father(x);
	y = father(y);
	if (x != y) par[y] = x;
	return x != y;
}

pair<int, pii> e[MAXM];

int main () {
	ios::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i ++) {
		int x, y, w; cin >> x >> y >> w; x--, y--;
		e[i] = mp(w, mp(x, y));
	}

	fill(par, par + n, -1);
	sort(e, e + m);

	int ans = 0;
	for (int i = 0; i < m; i ++) {
		int x = father(e[i].Y.X), y = father(e[i].Y.Y), w = e[i].X;
		
		if(merge(x, y))
			ans += w;
	}

	cout << ans << endl;
	return 0;
}

