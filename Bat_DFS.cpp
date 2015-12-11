#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int N=1000 *100+5;
vector <int> adj[N];
short mrk[N];

void dfs(int v){
	for(int i=0;i<adj[v].size();++i){
		cerr<<"debug:"<<v<<" "<<adj[v][i]<<endl;
		if(!mrk[adj[v][i]]++){
			dfs(adj[v][i]);
		}
	}
}

int main(){
	int n,m,t1,t2,s;
	cin>>n>>m>>s;
	for(int i=0;i<m;++i){
		cin>>t1>>t2;
		adj[t1].push_back(t2);
		adj[t2].push_back(t1);
	}
	mrk[s]=1;
	dfs(s);
	for(int i=1;i<n+1;++i){
		cout<<mrk[i]<<endl;
	}
	return 0;
}