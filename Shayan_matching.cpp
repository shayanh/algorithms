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

const int MAXN = 50 * 1000 + 10;

int match[3][MAXN];
bool mark[MAXN];
vector<int> adj[MAXN];
int n, m, p;

bool dfs(int x) {
	if (mark[x]) return false;

	mark[x] = true;
	for (int i = 0; i < SZ(adj[x]); i ++) {
		int v = adj[x][i];
		if (match[1][v] == -1 || dfs(match[1][v])) {
			match[0][x] = v;
			match[1][v] = x;
			return true;
		}
	}
	return false;
}

void bi_match() {
	CLR(match, -1);
	for (int i = 0; i < n; i ++) {
		CLR(mark, 0);
		bool check = false;
		for (int j = 0; j < n; j ++)
			if (!mark[j] && match[0][j] == -1) 
				check |= dfs(j);
		if (!check) break;
	}
}

int main () {
	ios::sync_with_stdio(false);
	
	cin >> n >> m >> p;
	for (int i = 0; i < p; i ++) {
		int x, y; cin >> x >> y; x --, y --;
		adj[x].pb(y);
	}

	bi_match();
	int ans = 0;
	FOR(i, n) ans += (match[0][i] != -1);
	cout << ans << endl;
	return 0;
}

