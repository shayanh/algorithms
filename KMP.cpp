#define SZ(x) (int)((x).size())

const int M = 1000 * 100 + 4;
int f[M];
string s,t;
bool match[M];
void kmp() {
	f[0] = -1;
	int pos = -1;
	for (int i = 1; i <= SZ(t); i++) {
		while(pos != -1 && t[pos] != t[i - 1]) pos = f[pos];
		f[i] = ++pos;
	}
	pos = 0;
	for (int i = 0; i < SZ(s); i++)	{
		while(pos != -1 && (pos == SZ(t) || s[i] != t[pos])) pos = f[pos];
		pos ++;
		if (pos == SZ(t)) match[i] = 1;
		else match[i] = 0;
	}
}
