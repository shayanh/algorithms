const int N = 1000 * 100 + 5;
vector <pii> adj[N];
int ans, mrk[N];

void prim(int v) {
	int w;
	set <pii> st;
	st.insert(mp(0, v));
	while(!st.empty()) {
		v = st.begin()-> Y;
		w = st.begin()-> X;
		st.erase(st.begin());
		if(mrk[v]++) continue;
		ans += w;

		for(int i = 0;i < Size(adj[v]);++i)
			if(!mrk[adj[v][i].Y])
				st.insert(adj[v][i]);
	}
}
