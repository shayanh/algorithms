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

