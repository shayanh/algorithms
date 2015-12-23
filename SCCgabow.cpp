vector <int> adj[N];
stack <int> S, P;
int mrk[N], ind, col[N], CL;

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
		col[v] = ++CL;
		while(P.top() != v) {
			col[P.top()] = CL;
			mrk[P.top()] = INF;
			P.pop();
		}
		P.pop();
		S.pop();
	}
}

//main: for(int i = 1;i <= n;++i)
//			if(!mrk[i]) dfs(i);
