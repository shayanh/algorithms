#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;
#define Size(x) (int)(x).size()

const int N = 1000 * 100 + 5, INF = 1000 * 1000 * 1000;
vector <int> adj[N];
stack <int> S, P;
int mrk[N], ind;

void dfs(int v) {
	mrk[v] = ++ind;
	S.push(v);
	P.push(v);
	for(int i = 0;i < Size(adj[v]);++i) {
		int u = adj[v][i];
		if(!mrk[u])
			dfs(u);
		else
			while(mrk[u] < mrk[S.top()])
				S.pop();
	}
	if(S.top() == v) {
		mrk[v] = INF;
		cout << "SCC: " << v;
		while(P.top() != v) {
			cout << " " << P.top();
			mrk[P.top()] = INF;
			P.pop();
		}
		cout << endl;
		P.pop();
		S.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n, m, a, b;
	cin >> n >> m;
	for(int i = 0;i < m;++i) {
		cin >> a >> b;
		adj[a].push_back(b);
	}
	for(int i = 1;i <= n;++i)
		if(!mrk[i])
			dfs(i);
	return 0;
}