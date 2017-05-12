int c[MAXN], a[MAXN];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	for (int i = 0; i <= n; i ++) c[i] = 1e9;
	
	int ans = 0;
	for (int i = 0; i < n; i ++) {
		int l = 0, r = i + 1;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (c[mid] <= a[i]) l = mid;
			else r = mid;
		}
		ans = max(ans, l + 1);
		if (c[l + 1] > a[i]) c[l + 1] = a[i];
	}
	cout << ans << endl;
} 
