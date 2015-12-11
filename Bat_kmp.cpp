#include<iostream>
#include<string>

using namespace std;

const int maxn=1000*1000+1000;

string s,t;
int f[maxn],g[maxn];
int p=-1;

int main()
{
	cin>>s>>t;
	for(int i=1;i<t.size();i++)
	{
		int q=f[i-1];
		while(t[i]!=t[q] && q>0) q=f[q-1];
		if(t[q]==t[i]) f[i]=q+1;
	}
	if(t[0]==s[0]) g[0]=1;
	for(int i=1;i<s.size();i++)
	{
		int q=g[i-1];
		while(s[i]!=t[q] && q>0) q=f[q-1];
		if(s[i]==t[q]) g[i]=q+1;
		if(g[i]==t.size())
		{
			p=i;
			break;
		}
	}
	if(p==-1) cout<<"Impossible"<<endl;
	else cout<<p<<endl;
	return 0;
}
