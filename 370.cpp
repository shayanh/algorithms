bool mark[MAXN];
vector<int> dv[MAXN];
int n, m;

// counts positive integers up to n that are relatively prime to x
int f(int x) {
	int res = 0;
	for (int mask = 0; mask < (1 << SZ(dv[x])); mask ++) {
		int t = __builtin_popcount(mask), a = n - 1;
		for (int i = 0; i < SZ(dv[x]); i ++)
			if (mask & (1 << i))
				a /= dv[x][i];
		if (t & 1) res -= a;
		else res += a;
	}
	return res;
}

int main () {
	for (int i = 2; i < n; i ++)
		if (!mark[i]) {	
			for (int j = i; j < m; j += i) {
				mark[j] = true;
				dv[j].pb(i);
			}
		}
	ll ans = 2;
	for (int i = 1; i < m; i ++) ans += f(i);
	cout << ans << endl;
	return 0;
}

