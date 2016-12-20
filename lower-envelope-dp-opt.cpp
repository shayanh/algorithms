//Usaco-Acquire
#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair <ll,ll> pii;
#define X first
#define Y second
#define Size(x) (int)(x).size()
#define mp(x,y) make_pair(x,y)

const int N = 1000 * 100 + 5;
deque <pii> dq;
pii a[N], b[N];
ll dp[N];
bool mrk[N];

int main() {
	ios::sync_with_stdio(false);
	int n, mm = -1, p = 0;
	cin >> n;
	for(int i = 0;i < n;++i)
		cin >> a[i].X >> a[i].Y;
	sort(a, a + n);
	for(int i = n - 1;i > -1;--i)
		if(a[i].Y <= mm)
			mrk[i] = 1;
		else
			mm  = a[i].Y;
	for(int i = 0;i < n;++i)
		if(!mrk[i])
			b[p++] = a[i];
	///
	for(int i = 0;i < p;++i) {
		while(Size(dq) > 1 && (dp[i] - dq.back().Y) * (dq[Size(dq) - 2].X - b[i].Y) < (dp[i] - dq[Size(dq) - 2].Y) * (dq.back().X - b[i].Y))
			dq.pop_back();
		dq.push_back(mp(b[i].Y, dp[i]));
		while(Size(dq) > 1 && dq[0].X * b[i].X + dq[0].Y >= dq[1].X * b[i].X + dq[1].Y)
			dq.pop_front();
		dp[i + 1] = dq[0].X * b[i].X + dq[0].Y;
	}
	cout << dp[p] << endl;
	return 0;
}
