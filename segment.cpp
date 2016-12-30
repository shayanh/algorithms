int v1[4 * MAXN];

// lo, hi -> [)
// s = 0, e = n, x = 1

void update1(int lo, int hi, int s, int e, int x, int val) {
	if (lo == s && hi == e) {
		v1[x] = val;
		return ;
	}
	int mid = (s + e) / 2;
	if (lo < mid) update1(lo, min(hi, mid), s, mid, x + x + 0, val);
	if (hi > mid) update1(max(lo, mid), hi, mid, e, x + x + 1, val);
}

int get1(int k, int s, int e, int x) {
	if (e - s < 2) return v1[x];
	int mid = (s + e) / 2;
	return max(v1[x], ((k < mid) ? get1(k, s, mid, x + x + 0) : get1(k, mid, e, x + x + 1)));
}

int v2[4 * MAXN];

void update2(int k, int s, int e, int x, int val) {
	if (e - s < 2) {
		v2[x] = val;
		return ;
	}
	int mid = (s + e) / 2;
	if (k < mid) update2(k, s, mid, x + x + 0, val);
	else         update2(k, mid, e, x + x + 1, val);
	v2[x] = max(v2[x + x + 0], v2[x + x + 1]);
}

int get2(int lo, int hi, int s, int e, int x) {
	if (lo == s && hi == e) return v2[x];
	int mid = (s + e) / 2, ans = 0;
	if (lo < mid) ans = max(ans, get2(lo, min(hi, mid), s, mid, x + x + 0));
	if (hi > mid) ans = max(ans, get2(max(lo, mid), hi, mid, e, x + x + 1));
	return ans;
}

