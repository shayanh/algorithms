#include <iostream>
#include <vector>
using namespace std;

const int N = 1000 * 100 + 5;
vector <int> adj[N];

int is_av[N], _sz[N]; //XXX initiate is_av to 1

void set_size(int v, int p) {
	_sz[v] = 1;
	for(int u:adj[v])
		if(u != p && is_av[u]) {
			set_size(u, v);
			_sz[v] += _sz[u];
		}
}

void divide(int v) {
	set_size(v, v);
	int S = _sz[v], p = v;
    sign:
    	for(int u:adj[v])
    		if(is_av[u] && u != p && _sz[u] > S / 2) {
    			p = v;
    			v = u;
    			goto sign;
    		}

    // now v is the centroid of the tree
    // Enter your code here

	is_av[v] = 0;
	for(int u:adj[v])
		if(is_av[u])
			divide(u);
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1;i < n;++i) {
		int a, b;
		cin >> a >> b;
		—-a, —-b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	fill(is_av, is_av + N, 1);
	divide(0);
	return 0;
}