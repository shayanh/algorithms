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

fill(par, par + n, -1);
