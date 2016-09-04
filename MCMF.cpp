#include <iostream>
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
F cap[MAXE];
C cost[MAXE],dist[MAXV],pot[MAXV];
int to[MAXE],prv[MAXE],last[MAXV],path[MAXV];
bool used[MAXV];
priority_queue <pair <C, int> > q;

//output
F flow[MAXE];

class MinCostFlow {
public:
    MinCostFlow(int n);
    int add_edge(int x, int y, F w, C c); // zero based && directed!
    pair <F, C> mincostflow(int s, int t);
private:
    pair <F, C> search(int s, int t);
    void bellman(int s);
};

///////////////////////////BACKEND!/////////////////////////
MinCostFlow::MinCostFlow(int n){
    V = n; E = 0;
    int i; REP(i,V) last[i] = -1;
}
int MinCostFlow::add_edge(int x, int y, F w, C c){
    cap[E] = w; flow[E] = 0; cost[E] = c; to[E] = y; prv[E] = last[x]; last[x] = E; E++;
    cap[E] = 0; flow[E] = 0; cost[E] = -c; to[E] = x; prv[E] = last[y]; last[y] = E; E++;
    return E-2;
}
void MinCostFlow::bellman(int s){
    int i,x,e;
    REP(i,V) pot[i] = C_INF;
    pot[s] = 0;
    REP(i,V+10) REP(x,V) for(e=last[x];e>=0;e=prv[e]) if(cap[e] > 0) pot[to[e]] = min(pot[to[e]], pot[x] + cost[e]);
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
        for(int e=path[t];e>=0;e=path[to[e^1]]) {ansc += cost[e] * ansf; cap[e] -= ansf; cap[e^1] += ansf; flow[e] += ansf; flow[e^1] -= ansf;}
    }
    return make_pair(ansf,ansc);
}
pair <F, C> MinCostFlow::mincostflow(int s, int t){
    F ansf=0; C ansc=0;
    int i;
    bellman(s);
    while(1){
        pair <F, C> p = search(s,t);
        if(!used[t]) break;
        ansf += p.first; ansc += p.second;
    }
    return make_pair(ansf,ansc);
}
////////////////////////////////////////////////////

int main() {
    return 0;
}
