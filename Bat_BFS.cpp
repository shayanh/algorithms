#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

const int N = 1000 *1000 +5;
vector <int> adj[N];
int dis[N];
short mrk[N];

void bfs(int v){
	queue <int> q;
	q.push(v);
	dis[v]=0;
	mrk[v]=1;
	while(!q.empty()){
		v=q.front();
		q.pop();
		for(int i=0;i<adj[v].size();++i){
			if(!mrk[adj[v][i]]++){
				q.push(adj[v][i]);
				dis[adj[v][i]]=dis[v]+1;
			}
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
	bfs(s);
	for(int i=1;i<n+1;++i)
		cout<<i<<" "<<dis[i]<<endl;
	return 0;
}