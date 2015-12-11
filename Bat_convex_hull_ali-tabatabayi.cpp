//In The Name Of God.
//CodeBreaker!

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<queue>
#include<map>
#include<utility>
#include<list>
#include<fstream>
#include<iomanip>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

#define PB push_back
#define PII pair <int,int>
#define PDD pair <double,double>
#define MP make_pair
#define X real()
#define Y imag()
#define F first
#define S second
#define ll long long

typedef complex < double > point;

const int maxn=100*1000+100;
const double eps=1e-8;

vector < point > v;
point p[maxn];
int n;

double cross(point a,point b)
{
	return imag(b*conj(a));
}

bool cmp1(point x,point y)
{
	return ( x.X<y.X || (x.X==y.X && x.Y<y.Y) );
}

bool cmp2(point x,point y)
{
	return ( cross(x-p[0],y-p[0])>0 || ( cross(x-p[0],y-p[0])==0 && abs(x-p[0])<abs(y-p[0]) ) );
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>p[i].X>>p[i].Y;
	sort(p,p+n,cmp1);
	sort(p+1,p+n,cmp2);
	v.PB(p[0]);
	for(int i=1;i<n;i++)
	{
		while(v.size()>1 && cross(p[i]-v[v.size()-2],v[v.size()-1]-v[v.size()-2])>-eps) v.pop_back();
		v.PB(p[i]);
	}
	for(int i=0;i<v.size();i++) cout<<v[i]<<endl;
	return 0;
}