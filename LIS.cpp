#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int, int>
#define CLR(x, a) memset(x, a, sizeof x)
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)x.size())
#define VAL(x) #x << " = " << x << "   "
#define X first
#define Y second

const int MAXN = 100 * 1000 + 10;

int c[MAXN], a[MAXN];

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	for (int i = 0; i <= n; i ++) c[i] = 1e9;
	
	int ans = 0;
	for (int i = 0; i < n; i ++) {
		int l = 0, r = i + 1;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (c[mid] <= a[i]) l = mid;
			else r = mid;
		}
		ans = max(ans, l + 1);
		if (c[l + 1] > a[i]) c[l + 1] = a[i];
	}
	cout << ans << endl;
	return 0;
} 
