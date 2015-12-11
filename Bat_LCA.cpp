#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int N=2000*100,LOG=20;
vector <int> adj[N];
int pa[N][LOG],lev[N];
short mrk[N];

void update(int s,int d){
	pa[s][0]=d;
	for(int i=0;i<LOG-1;++i){
		pa[s][i+1]=pa[d][i];
		if(pa[d][i] != -1)
			d=pa[d][i];
	}
}

int move(int x,int dis){
	for(int i=LOG-1;i>-1;--i){
		if(x  ==  -1) break;
		if(dis & (1<<i))
			x=pa[x][i];
	}
	return x;
}

int find_par(int x,int y){
	if(lev[x] > lev[y]) swap(x,y);
	y=move(y,lev[y]-lev[x]);
	int s=0,e=lev[x];
	while(e != s){
		int m=(s+e)/2;
		if(move(x,m)  ==  move(y,m))	e=m;
		else s=m+1;
	}
	return move(x,e);
}

void dfs(int v){
	for(int i=0;i<adj[v].size();++i){
		if(!mrk[adj[v][i]]++){
			update(adj[v][i],v);
			lev[adj[v][i]]=lev[v]+1;
			dfs(adj[v][i]);
		}
	}
}

int main(){
	int n,t1,t2,source;
	cin>>n>>source;
	for(int i=0;i<n-1;++i){
		cin>>t1>>t2;
		adj[t1].push_back(t2);
		adj[t2].push_back(t1);
	}
	for(int i=0;i<LOG;++i) pa[source][i]=-1;
	++mrk[source];
	dfs(source);
	int q;
	cin>>q;
	for(int i=0;i<q;++i){
		cin>>t1>>t2;
		cout<<find_par(t1,t2)<<endl;
// 		cout<<move(t1,t2);
	}
	return 0;
}