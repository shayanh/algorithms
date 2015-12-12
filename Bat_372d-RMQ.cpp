#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;
typedef pair <int,int> pii;
#define error(x) cout << #x << " = " << (x) << endl;
#define Size(x) (int)(x).size()
#define X first
#define Y second
#define mp(x,y) make_pair(x,y)

const int N = 3000 * 100 + 5, LOG = 23, INF = 1000 * 1000 * 1000;
set <int> st;
set <int> ::iterator it;
vector <pii> PT;
vector <int> adj[N];
pii RMQ[N][LOG];
int S[N], s[N], f[N], tim, log[N], h[N], par[N][LOG];

void update(int v, int u) {
	par[v][0] = u;
	for(int i = 1;i < LOG;++i)
		u = par[u][i - 1],
		par[v][i] = u;
}

void init() {
	int c = 0, p = 1;
	for(int i = 1;i < N;++i) {
		if(i == p << 1) {
			p <<= 1;
			++c;
		}
		log[i] = c;
	}
}

void dfs(int v, int par) {
	S[v] = Size(PT);
	s[v] = ++tim;
	PT.push_back(mp(h[v], v));
	for(int i = 0;i < Size(adj[v]);++i)
		if(adj[v][i] != par) {
			h[adj[v][i]] = h[v] + 1;
			update(adj[v][i], v);
			dfs(adj[v][i], v);
			PT.push_back(mp(h[v], v));
		}
	f[v] = ++tim;
}

inline int find_par(int v, int u) {
	if(S[v] > S[u])
		swap(v, u);
	int tmp = log[S[u] - S[v] + 1];
	return min(RMQ[S[v]][tmp], RMQ[S[u] - (1 << tmp) + 1][tmp]).Y;
}

class segment{
	int P[4 * N], Q[4 * N], L[4 * N];
public:
	void build(int x, int p, int q) {
		P[x] = p;
		Q[x] = q;
		if(p == q) {
			L[x] = p;
			return ;
		}
		int m = (p + q) >> 1;
		build(x << 1, p, m);
		build((x << 1) + 1, m + 1, q);
		L[x] = find_par(L[x << 1], L[(x << 1) + 1]);
	}
	int find(int x, int p, int q) {
		if(p <= P[x] && Q[x] <= q)
			return L[x];
		int m = (P[x] + Q[x]) >> 1;
		if(q <= m)
			return find(x << 1, p, q);
		if(p > m)
			return find((x << 1) + 1, p, q);
		return find_par(find(x << 1, p, m), find((x << 1) + 1, m + 1, q));
	}
} T;

int IF_add(int u,int v) {
	if(s[v] <= s[u] && f[u] <= f[v]) {
		if(*st.lower_bound(s[u]) < f[u])
			return 0;
		int tmp = h[u];
		for(int i = LOG - 1;i > -1;--i) {
			if(!par[u][i])
				continue;
			int k = *st.lower_bound(s[par[u][i]]);
			if(k > f[par[u][i]])
				u = par[u][i];
		}
		return tmp - h[u] + 1;
	}
	else {
		return h[v] + h[u] - 2 * h[find_par(u, v)];
	}
}

int main() {
// 	ios::sync_with_stdio(false);
	init();
	int n, k, a, b;
	cin >> n >> k;
	for(int i = 1;i < n;++i) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);
	for(int i = Size(PT) - 1;i > -1;--i) {
		RMQ[i][0] = PT[i];
		for(int j = 1;j < LOG && i + (1 << j) <= Size(PT);++j)
			RMQ[i][j] = min(RMQ[i][j - 1], RMQ[i + (1 << (j - 1))][j - 1]);
	}
	T.build(1, 1, n);
	///
	st.insert(INF);
	int p = 0, cost = 1, ans = 1, LCA = 1;
	for(int i = 1;i <= n;++i) {
		if(p < i) {
			st.insert(s[i]);
			p = i;
			cost = 1;
			LCA = i;
		}
		while(p < n) {
			int tmp = IF_add(p + 1, LCA);
			if(cost + tmp > k)
				break;
			cost += tmp;
			st.insert(s[++p]);
			LCA = find_par(LCA, p);
		}
		st.erase(s[i]);
		if(p > i) {
			ans = max(ans, p - i + 1);
			int tmp = T.find(1, i + 1, p);
			cost -= IF_add(i, tmp);
			LCA = tmp;
		}
	}
	cout << ans << endl;
	return 0;
}