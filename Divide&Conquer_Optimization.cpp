//321e
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

const int N = 4000 + 5, INF = 1000 * 1000 * 1000;
int dp[N][N], F[N][N], l;

void solve(int x, int y, int s, int e) {
	if(x > y)
		return ;
	int m = (x + y) >> 1, t;
	dp[m][l] = INF;
	for(int i = s;i <= min(e, m);++i) {
		if(dp[i][l - 1] + F[i + 1][m] < dp[m][l]) {
			dp[m][l] = dp[i][l - 1] + F[i + 1][m];
			t = i;
		}
	}
	solve(x, m - 1, s, t);
	solve(m + 1, y, t, e);
}

int main() {
	ios::sync_with_stdio(false);
	int n, k, S[N] = {0};
	cin >> n >> k;
	for(int i = 1;i <= n;++i) {
		for(int j = 1;j <= n;++j)
			cin >> S[j],
			S[j] += S[j - 1];
		for(int j = 1;j <= i;++j)
			F[j][i] = (S[i] - S[j - 1]) + F[j][i - 1];
	}
	///
	for(int i = 1;i <= n;++i) {
		dp[i][1] = F[1][i];
		dp[i][0] = INF;
	}
	for(l = 2;l <= k;++l)
		solve(1, n, 1, n);
	cout << dp[n][k] << endl;
	return 0;
}
