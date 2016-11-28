#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define CLR(x, a) memset(x, a, sizeof x)
#define VAL(x) #x << " = " << (x) << "   "
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define FOR(i, n) for (int i = 0; i < (n); i ++)
#define X first
#define Y second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int MAXN = 1 * 1000 + 10, MOD = 1e9 + 7;

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

int main () {
	ios::sync_with_stdio(false);

	init(10);
	cout << C(5, 2) << endl;
	return 0;
}

