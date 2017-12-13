int seg[4 * MAXN], add[4 * MAXN];

inline void shift(int x, int s, int e) {
	int lc = x + x + 0, rc = x + x + 1;

	int mid = (s + e) / 2;
	int l1 = mid - s, l2 = e - mid;

	seg[lc] += l1 * add[x];
	seg[rc] += l2 * add[x];
	add[lc] += add[x];
	add[rc] += add[x];
	
	add[x] = 0;
}

// lo, hi -> [)
// s = 0, e = n, x = 1

void update(int lo, int hi, int s, int e, int x, int delta) {
	if (lo == s && hi == e) {
		int len = (e - s);
		seg[x] = seg[x] + len * delta;
		add[x] = add[x] + delta;
		return ;
	}
	shift(x, s, e);

	int mid = (s + e) / 2;
	int lc = x + x + 0, rc = x + x + 1;
	if (lo < mid) update(lo, min(mid, hi), s, mid, lc, delta);
	if (hi > mid) update(max(lo, mid), hi, mid, e, rc, delta);

	seg[x] = seg[lc] + seg[rc];
}

int get(int lo, int hi, int s, int e, int x) {
	if (lo == s && hi == e) return seg[x];
	shift(x, s, e);

	int mid = (s + e) / 2;
	int res = 0;
	if (lo < mid) res += get(lo, min(mid, hi), s, mid, x + x + 0);
	if (hi > mid) res += get(max(lo, mid), hi, mid, e, x + x + 1);

	return res;
}
