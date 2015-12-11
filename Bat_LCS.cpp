#include <iostream>
using namespace std;
typedef long long ll;

const int N=1000*10+5;
string s,t;
int dp[N][N];
short mrk[N][N];

int dpf(int x,int y){
	if(x<0  ||  y<0) return 0;
	if(mrk[x][y])
		return dp[x][y];
	mrk[x][y]=1;
	if(s[x]  ==  t[y]){
		dp[x][y]=dpf(x-1,y-1)+1;
		return dp[x][y];
	}
	dp[x][y]=max(dpf(x-1,y),dpf(x,y-1));
	return dp[x][y];
}

int main(){
	cin>>s>>t;
	cout<<dpf(s.size()-1,t.size()-1)<<endl;
	return 0;
}