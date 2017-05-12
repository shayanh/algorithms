int min_val[4 * MAXN], rgt_min[4 * MAXN], add[4 * MAXN];

inline void shift(int x) {
	int lc = x + x + 0, rc = x + x + 1;
	if (add[x]) {
		min_val[lc] += add[x];
		min_val[rc] += add[x];
		add[lc] += add[x];
		add[rc] += add[x];
	}
	add[x] = 0;
}

// lo, hi -> [)
// s = 0, e = n, x = 1

void update2(int lo, int hi, int s, int e, int x, int delta) {
	if (lo == s && hi == e) {
		min_val[x] += delta;
		add[x] += delta;
		return ;
	}
	shift(x);

	int mid = (s + e) / 2;
	if (lo < mid) update2(lo, min(mid, hi), s, mid, x + x + 0, delta);
	if (hi > mid) update2(max(lo, mid), hi, mid, e, x + x + 1, delta);

	int lc = x + x + 0, rc = x + x + 1;
	min_val[x] = min(min_val[lc], min_val[rc]);
	if (min_val[rc] <= min_val[lc]) rgt_min[x] = rgt_min[rc] + mid - s;
	else rgt_min[x] = rgt_min[lc];
}

pii get2(int lo, int hi, int s, int e, int x) {
	if (lo == s && hi == e) return mp(min_val[x], rgt_min[x]);
	shift(x);

	int mid = (s + e) / 2;
	pii tmp1 = mp(INF, -1), tmp2 = mp(INF, -1);
	if (lo < mid) tmp1 = get2(lo, min(mid, hi), s, mid, x + x + 0);
	if (hi > mid) tmp2 = get2(max(lo, mid), hi, mid, e, x + x + 1);

	if (tmp2.X <= tmp1.X) return mp(tmp2.X, tmp2.Y + (lo < mid ? mid - lo : 0));
	else return mp(tmp1.X, tmp1.Y);
}

