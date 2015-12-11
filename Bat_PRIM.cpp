#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;
typedef pair <int,int> pii;
#define mp(x,y) make_pair(x,y)

const int N=1000*100+5;
vector <pii> adj[N];
int ans;
short mrk[N];

void dijkstra(int v){
	int w;
	set <pii> st;
	st.insert(mp(0,v));
	while(!st.empty()){
		v=st.begin()->second;
		w=st.begin()->first;
		st.erase(st.begin());
		if(mrk[v]) continue;
		ans+=w;
		mrk[v]=1;
		for(int i=0;i<adj[v].size();++i){
			if(!mrk[adj[v][i].second])
				st.insert(mp(adj[v][i].first,adj[v][i].second));
		}
	}
}

int main(){
	int n,m,t1,t2,cost;
	cin>>n>>m;
	for(int i=0;i<m;++i){
		cin>>t1>>t2>>cost;
		adj[t1].push_back(mp(cost,t2));
		adj[t2].push_back(mp(cost,t1));
	}
	dijkstra(1);
	cout<<ans<<endl;
	return 0;
}