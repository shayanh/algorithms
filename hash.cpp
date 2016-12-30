ll p[MAXN], hash[MAXN];

int main () {
	p[0] = 1;
	for (int i = 1; i < MAXN; i ++)
		p[i] = p[i - 1] * BASE;

	string s;
	getline(cin, s);

	for (int i = 1; i <= SZ(s); i ++)
		hash[i] = hash[i - 1] * BASE + s[i - 1];


	// hash in [i, j], 1-based
	ll h = hash[j] - (hash[i - 1] * p[j - i + 1]); 
}

