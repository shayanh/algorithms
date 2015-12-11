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

const int MAXN = 1 * 1000 + 10;

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

int main () {
	ios::sync_with_stdio(false);
	return 0;
}

