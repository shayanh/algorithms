#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

//XXX change these lines!
typedef int F;
typedef long long C;
#define F_INF (1<<29)
#define C_INF (1LL<<60)
#define MAXV 3000
#define MAXE 10000 // E*2! [or E*4 for bidirected graphs]

//no need to initialize these variables!
int V,E;
F cap[MAXE],flow[MAXE];
C cost[MAXE],dist[MAXV],pot[MAXV];
int to[MAXE],prv[MAXE],last[MAXV],path[MAXV];
bool used[MAXV];
priority_queue <pair <C, int> > q;

class MinCostFlow {
public:
    MinCostFlow(int n);

    void add_edge(int x, int y, F w, C c); // zero based && directed!

    pair <F, C> search(int s, int t);

    pair <F, C> mincostflow(int s, int t);

    vector <pair <int, int> > flow_edges(void);
};

vector <pair <int, int> > MinCostFlow::flow_edges(void) {
    int x, e;
    vector <pair <int, int> > ans;
    REP(x,V) for(e=last[x];e>=0;e=prv[e]) if(flow[e] > 0) ans.push_back(make_pair(x,to[e]));
    return ans;
}

MinCostFlow::MinCostFlow(int n){
    V = n; E = 0;
    int i; REP(i,V) last[i] = -1;
}

void MinCostFlow::add_edge(int x, int y, F w, C c){
    cap[E] = w; flow[E] = 0; cost[E] = c; to[E] = y; prv[E] = last[x]; last[x] = E; E++;
    cap[E] = 0; flow[E] = 0; cost[E] = -c; to[E] = x; prv[E] = last[y]; last[y] = E; E++;
}

pair <F, C> MinCostFlow::search(int s, int t){
    F ansf=0; C ansc=0;
    int i;

    REP(i,V) used[i] = false;
    REP(i,V) dist[i] = C_INF;

    dist[s] = 0; path[s] = -1; q.push(make_pair(0,s));
    while(!q.empty()){
        int x = q.top().second; q.pop();
        if(used[x]) continue; used[x] = true;
        for(int e=last[x];e>=0;e=prv[e]) if(cap[e] > 0){
            C tmp = dist[x] + cost[e] + pot[x] - pot[to[e]];
            if(tmp < dist[to[e]] && !used[to[e]]){
                dist[to[e]] = tmp;
                path[to[e]] = e;
                q.push(make_pair(-dist[to[e]],to[e]));
            }
        }
    }

    REP(i,V) pot[i] += dist[i];

    if(used[t]){
        ansf = F_INF;
        for(int e=path[t];e>=0;e=path[to[e^1]]) ansf = min(ansf,cap[e]);
        for(int e=path[t];e>=0;e=path[to[e^1]]) {ansc += cost[e] * ansf; cap[e] -= ansf; flow[e] += ansf; cap[e^1] += ansf; flow[e^1] -= ansf;}
    }

    return make_pair(ansf,ansc);
}

pair <F, C> MinCostFlow::mincostflow(int s, int t){
    F ansf=0; C ansc=0;
    int i;
    REP(i,V) pot[i] = 0;
    while(1){
        pair <F, C> p = search(s,t);
        if(!used[t]) break;
        ansf += p.first; ansc += p.second;
    }
    return make_pair(ansf,ansc);
}

int main() {
    return 0;
}
