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

const int MAXN = 100 * 1000 + 10, INF = INT_MAX, MOD = 1e9 + 7, BASE = 701;

ll p[MAXN], hash[MAXN];

int main ()
{
	ios::sync_with_stdio(false);

	p[0] = 1;
	for (int i = 1; i < MAXN; i ++)
		p[i] = p[i - 1] * BASE;

	string s;
	getline(cin, s);

	for (int i = 1; i <= SZ(s); i ++)
		hash[i] = hash[i - 1] * BASE + s[i - 1];

	string t, ans;
	int pos = 0;

	for (int i = 0; i < SZ(s); i ++) ans.pb('_');

	while (cin >> t)
	{
		pos += SZ(t);
		ll h = 0;
		for (int i = 0; i < SZ(t); i ++)
			h = h * BASE + t[i];
		bool found = false;
		for (; pos <= SZ(s); pos ++)
		{
			ll cur = hash[pos] - (hash[pos - SZ(t)] * p[SZ(t)]);
			if (cur == h)
			{
				for (int i = pos - SZ(t); i < pos; i ++)
					ans[i] = s[i];
				found = true;
				break;
			}
		}
		pos += 1;
		if (!found)
		{
			cout << "I HAVE FAILED!!!\n";
			return 0;
		}
	}
	for (int i = 0; i < SZ(s); i ++) if (s[i] == ' ') ans[i] = ' ';
	cout << ans << endl;
	return 0;
}

