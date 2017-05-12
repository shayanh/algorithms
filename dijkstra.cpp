const int MAXN = 10 * 1000 + 10;
const ll INF = 1e9;

ll dis[MAXN];
set<pii> s;
bool mark[MAXN];
vector<pii> adj[MAXN];

void dij(int start) {
	for (int i = 0; i < MAXN; i ++) dis[i] = INF;

	CLR(mark, 0); s.clear();
	mark[start] = true;
	dis[start] = 0;
	s.insert(mp(0, start));

	while (SZ(s)) {
		int x = s.begin()->Y; s.erase(s.begin());

		for (int i = 0; i < SZ(adj[x]); i ++) {
			int v = adj[x][i].X, w = adj[x][i].Y;
			if (dis[v] > dis[x] + w) {
				if (mark[v]) s.erase(mp(dis[v], v));
				else mark[v] = true;
	
				dis[v] = dis[x] + w;
				s.insert(mp(dis[v], v));
			}
		}
	}
}
