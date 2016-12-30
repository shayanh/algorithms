int fen[MAXN]; // 0-based, [)

void add(int x, int val) {
	for (int i = x; i > 0; i -= i & (-i)) 
		fen[i] += val;
}

int get(int x) {
	int ans = 0;
	for (int i = x + 1; i < MAXN; i += i & (-i))
		ans += fen[i];
	return ans;
}

void update(int l, int r, int val) {
	add(r, +val);
	add(l, -val);
}

