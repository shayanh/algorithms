/**											Be name Khoda											**/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
using namespace std;

#define ll long long
#define un unsigned
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define VAL(x) #x << " = " << x << "   "
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define CLR(x, a) memset(x, a, sizeof x)
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define X first
#define Y second
#define PI (3.141592654)

//#define cout fout
//#define cin fin

//ifstream fin("problem.in");
//ofstream fout("problem.out");

const int MAXN = 1000 * 1000 + 10, INF = INT_MAX, MOD = 1e9 + 7;

bool mark[MAXN];
vector<int> dv[MAXN];
int n, m;

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
	ios::sync_with_stdio(false);

	cin >> n >> m;
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

