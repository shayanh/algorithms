#include <queue>
#include <cstring>

const int N = 100;
int mat[N][N];

int viz[N], network[N][N], parent[N];
bool anotherPath(int start, int end) {
	memset(viz, 0, sizeof viz);
	memset(parent, -1, sizeof parent);
	viz[start] = true;
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int z = q.front(); q.pop();
		viz[z] = true;
		for (int i=0;i<N;i++) {
			if (network[z][i] <= 0 || viz[i]) continue;
			viz[i] = true;
			parent[i] = z;
			if (i == end) return true;
			q.push(i);
		}
	}
	return false;
}
int maxflow(int start, int end) {
	memcpy(network, mat, sizeof(mat));
	int total = 0;
	while (anotherPath(start, end)) {
		int flow = network[parent[end]][end];
		int curr = end;
		while (parent[curr] >= 0) {
			flow = min(flow, network[parent[curr]][curr]);
			curr = parent[curr];
		}
		curr = end;
		while (parent[curr] >= 0) {
			network[parent[curr]][curr]-=flow;
			network[curr][parent[curr]]+=flow;
			curr = parent[curr];
		}
		total += flow;
	}
	return total;
}
