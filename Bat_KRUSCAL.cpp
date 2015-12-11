#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
#define X first
#define Y second
#define mp(x,y) make_pair(x,y)
#define Size(x) (int)(x).size()

const int N = 1000 * 100 + 5;
vector <piii> edl;
int par[N];

int fp(int x){
	return !par[x]?x:par[x] = fp(par[x]);
}

bool add(int v,int u){
	v = fp(v);
	u = fp(u);
	if(v != u)
		par[v] = u;
	return v != u;
}

int main(){
	ios::sync_with_stdio(false);
	edl.reserve(N);
	ll ans = 0;
	int n, m, a, b, c;
	cin >> n >> m;
	for(int i=0;i<m;++i){
		cin >> a >> b >> c;
		edl.push_back(mp(c,mp(a,b)));
	}
	sort(edl.begin(),edl.end());
	for(int i=0;i<m;++i)
		if(add(edl[i].Y.X,edl[i].Y.Y))
			ans += edl[i].X;
	cout << ans << endl;
	return 0;
}