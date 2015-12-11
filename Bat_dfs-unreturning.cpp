//short mrk[N];
//vector <int> adj[N];
void DFS(int v){
	stack <short> s;
	s.push(v);
	while(!s.empty()){
		while(!s.empty()  &&  mrk[s.top()]) s.pop();
		if(s.empty())
			break;
		v=s.top();
		s.pop();
		mrk[v]++;
		FOR(i,0,Size(adj[v]))
			if(!mrk[adj[v][i])
				s.push(v);
	}
}