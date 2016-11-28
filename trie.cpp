#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define CLR(x, a) memset(x, a, sizeof x)
#define VAL(x) #x << " = " << (x) << "   "
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define FOR(i, n) for (int i = 0; i < (n); i ++)
#define X first
#define Y second

const int MAXN = 10 * 1000 + 10, MAX = 26, INF = 1e9 + 10;

struct Node {
	char x;
	vector<Node*> adj;

	Node () {
		x = 0;
	}

	Node (char a) {
		x = a;
	}

	Node* add_edge(char a) {
		for (int i = 0; i < SZ(adj); i ++)
			if (adj[i]->x == a)
				return adj[i];
		adj.pb(new Node(a));
		return adj.back();
	}
};

struct Trie {
	Node* root;

	Trie() {
		root = new Node();
	}

	void add(string &s) {
		add(s, 0, root);
	}

	void add(string &s, int pos, Node* node) {
		if (pos == SZ(s)) {
			return ;
		} else {
			Node* next = node->add_edge(s[pos]);
			add(s, pos + 1, next);
		}
	}
};

int main () {
	return 0;
}

