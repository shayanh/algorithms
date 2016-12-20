//321e
#include <iostream>
using namespace std;
typedef long long ll;

const int N = 4000 + 5, INF = 1000 * 1000 * 1000;
int dp[N][N], u[N][N], F[N][N];

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
	u[0][0] = 1;
	for(int i = 1;i <= n;++i) {
		dp[i][1] = F[1][i];
		u[i][1] = 1;
		dp[i][0] = INF;
		u[i][0] = 1;
		u[n + 1][i] = n;
	}
	for(int j = 2;j <= n;++j) {
		for(int i = n;i >= j;--i) {
			int M = INF;
			for(int s = u[i][j - 1];s <= min(u[i + 1][j], i);++s) {
				if(dp[s - 1][j - 1] + F[s][i] < M) {
					M = dp[s - 1][j - 1] + F[s][i];
					u[i][j] = s;
				}
			}
			dp[i][j] = M;
		}
	}
	cout << dp[n][k] << endl;
	return 0;
}
