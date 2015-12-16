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

const int MAXN = 100 * 1000 + 10, BASE = 701;

ll p[MAXN], hash[MAXN];

int main () {
	ios::sync_with_stdio(false);

	p[0] = 1;
	for (int i = 1; i < MAXN; i ++)
		p[i] = p[i - 1] * BASE;

	string s;
	getline(cin, s);

	for (int i = 1; i <= SZ(s); i ++)
		hash[i] = hash[i - 1] * BASE + s[i - 1];


	// hash in [i, j], 1-based
	ll h = hash[j] - (hash[i - 1] * p[j - i + 1]); 
	return 0;
}

