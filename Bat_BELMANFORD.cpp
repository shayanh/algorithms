#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair <int,int> pii;

const int N = 1000 * 100, INF = 1000 * 1000 * 1000;
int cost[N], dis[N];
pii ed[N];
short mrk[N];

int main() {
	int n, m, source;
	cin >> n >> m >> source;
	for(int i = 0;i < m;++i)
		cin >> ed[i].first >> ed[i].second >> cost[i];
	fill(dis, dis + N, INF);
	mrk[source] = 1;
	dis[source] = 0;
	for(int i = 0;i < n;++i)
		for(int j = 0;j < m;++j)
			if(mrk[ed[j].first]) {
				mrk[ed[j].second]++;
				if(dis[ed[j].second] > dis[ed[j].first] + cost[j])
					dis[ed[j].second] = dis[ed[j].first] + cost[j];
			}
	for(int i = 1;i < n + 1;++i)
		if(dis[i]==INF)
			cout << "INF" << endl;
		else
			cout << dis[i] << endl;
	return 0;
}