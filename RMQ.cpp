const int N = 1000 * 100 + 5, LOG = 20;

class RMQ{
	int f[LOG][N], Lgl[N], S;
public:
	RMQ() {
		for(int i = 1, p = 0;i < N;++i) {
			if(i == 1 << (p + 1))
				++p;
			Lgl[i] = p;
		}
	}
	void build(int a[], int n) {
		for(int i = 0;i < n;++i)
			f[0][i] = a[i];

		for(int j = 1, p = 1; j < LOG; ++j, p *= 2)
			for(int i = 0;i < n;++i) {
				f[j][i] = f[j - 1][i];
				if(i + p < n)
					f[j][i] = min(f[j - 1][i], f[j - 1][i + p]);
			}
	}
	int find(int s, int e) {
		int l = Lgl[e - s + 1];
		return min(f[l][s], f[l][e + 1 - (1 << l)]);
	}
};
