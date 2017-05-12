ll bin_pow(ll x, ll y) {
	if (y == 0) return 1;

	ll tmp = bin_pow(x, y / 2);
	ll res = SQR(tmp) % MOD;
	if (y & 1) res = (res * x) % MOD;
	return res;
}

ll fct[MAXN], rev[MAXN], fct_rev[MAXN];

void init(int n) {
	fct[0] = 1;
	for (int i = 1; i <= n; i ++)
		fct[i] = (fct[i - 1] * i) % MOD;

	rev[0] = 1;
	for (int i = 1; i <= n; i ++)
		rev[i] = bin_pow(i, MOD - 2);

	fct_rev[0] = 1;
	for (int i = 1; i <= n; i ++)
		fct_rev[i] = (fct_rev[i - 1] * rev[i]) % MOD;
}

int C(int n, int r) {
	return (((fct[n] * fct_rev[r]) % MOD) * fct_rev[n - r]) % MOD;
}
