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
#define FOR(i, n) for (int i = 0; i < (n); ++ i)
#define X first
#define Y second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int MAXN = 100 * 1000 + 10;

vector<int> seg[4 * MAXN];
int a[MAXN];

void init(int x, int s, int e) {
	if (e - s < 2) {
		seg[x].pb(a[s]);
		return ;
	}
	int mid = (s + e) / 2;
	init(x + x, s, mid);
	init(x + x + 1, mid, e);
	
	seg[x].resize(e - s);
	merge(ALL(seg[x + x]), ALL(seg[x + x + 1]), seg[x].begin());
}

int get(int lo, int hi, int s, int e, int x, int k) {
	if (lo == s && hi == e) {
		int res = upper_bound(ALL(seg[x]), k) - seg[x].begin();
		return res;
	}
	int mid = (s + e) / 2, ans = 0;
	if (lo < mid) ans += get(lo, min(mid, hi), s, mid, x + x, k);
	if (hi > mid) ans += get(max(lo, mid), hi, mid, e, x + x + 1, k);
	return ans;
}

int main () {
	ios::sync_with_stdio(false);
	return 0;
}
