int mrk[N];
vector <int> adj[N];

void DFS(int v){
	stack <int> S;
	S.push(v);
	while(!S.empty()){
		while(!S.empty()  &&  mrk[S.top()]++)
			S.pop();
		if(S.empty())
			break;
		v = S.top(), S.pop();
		for(int i = 0; i< Size(adj[v]); ++i)
			if(!mrk[adj[v][i]])
				S.push(v);
	}
}
