#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int N = 1000 * 100 + 5;
vector <int> adj[N];
int mrk[N], h[N];
char ans[N];

void dfs(int v, int p) {
	h[v] = 1;
	for(int u:adj[v])
		if(u != p && mrk[u]) {
			dfs(u, v);
			h[v] += h[u];
		}
}

void algo(int v, char c) {
	dfs(v, v);
	int S = h[v], p = v;
sign:
	for(int u:adj[v])
		if(mrk[u] && u != p && h[u] > S / 2) {
			p = v;
			v = u;
			goto sign;
		}
	mrk[v] = 0;
	ans[v] = c;
	for(int u:adj[v])
		if(mrk[u])
			algo(u, c + 1);
}

int main() {
	ios::sync_with_stdio(false);
	int n, a, b;
	cin >> n;
	for(int i = 1;i < n;++i) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	fill(mrk, mrk + N, 1);
	algo(1, 'A');
	for(int i = 1;i <= n;++i)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
