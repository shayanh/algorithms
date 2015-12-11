#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define FOR(i,m,n) for(int i=m;i<n;++i)
#define MFOR(i,m,n) for(int i=m;i>n;--i)
#define mp(x,y) make_pair(x,y)

const int N=1000*100+5;
int num[N],fa[N],mrk[N];
vector <pair <int,int> > so;

void pr(int x){
	if(x==-1)
		return ;
	mrk[x]=1;
	pr(fa[x]);
	cout<<num[x]<<" ";
}

int main(){
	int n;
	cin>>n;
	FOR(i,0,n){
		cin>>num[i];
		if(!so.size()  ||  num[i]>so.back().first){
			if(!so.size()) fa[i]=-1;
			else fa[i]=so.back().second;
			so.push_back(mp(num[i],i));
		}
		else{
			int t=lower_bound(so.begin(),so.end(),mp(num[i],0))-so.begin();
			fa[i]=so[t-1].second;
			so[t]=mp(num[i],i);
		}
	}
	MFOR(i,n-1,-1)
		if(!mrk[i])
			pr(i),cout<<endl;
	return 0;
}