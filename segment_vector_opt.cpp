//Solution to problem 191e
// template <class T1>

class segment{
	vector <int> Rb[4 * N], Rs[4 * N], Lb[4 * N], Ls[4 * N];
	int P[4 * N], Q[4 * N];
public:
	vector <ll> S[4 * N];
	
	void build(int x, int p, int q, ll a[]) {
		P[x] = p;
		Q[x] = q;
		for(int i = p;i <= q;++i)
			S[x].push_back(a[i]);
		if(p == q)
			return ;
		
		int m = (p + q) >> 1, r = x << 1, l = (x << 1) + 1, po = 0, qo = 0;
		build(x << 1, p, m, a);
		build((x << 1) + 1, m + 1, q, a);
		///
		sort(S[x].begin(), S[x].end());
		
		for(int i = 0;i < Size(S[x]);++i) {
			while(po < Size(S[r]) && S[r][po] < S[x][i])
				++po;
			while(qo < Size(S[l]) && S[l][qo] < S[x][i])
				++qo;
			Rb[x].push_back(po);
			Lb[x].push_back(qo);
		}
		
		po = Size(S[r]) - 1;
		qo = Size(S[l]) - 1;
		for(int i = Size(S[x]) - 1;i > -1;--i) {
			while(po > -1 && S[r][po] > S[x][i])
				--po;
			while(qo > -1 && S[l][qo] > S[x][i])
				--qo;
			Rs[x].push_back(po);
			Ls[x].push_back(qo);
		}
		reverse(Rs[x].begin(), Rs[x].end());
		reverse(Ls[x].begin(), Ls[x].end());
	}
	int find(int x, int p, int q, int a, int b) {
		if(a == Size(S[x]) || b == -1 || a > b)
			return 0;
		if(q < P[x] || Q[x] < p)
			return 0;
		if(p <= P[x] && Q[x] <= q)
			return b - a + 1;
		int tmp = find(x << 1, p, q, Rb[x][a], Rs[x][b]);
		tmp += find((x << 1) + 1, p, q, Lb[x][a], Ls[x][b]);
		return tmp;
	}
} T;
