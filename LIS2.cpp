int fa[N];
vector <pair <int,int> > vl;

void LIS(int a[], int n) {
	for(int i = 0;i < n;++i) {
		if(!Size(vl)  ||  a[i] > vl.back().X)
			fa[i] = vl.empty()? -1: vl.back().second,
			vl.push_back(mp(a[i], i));
		else {
			int t = lower_bound(vl.begin(), vl.end(), mp(a[i],0))-vl.begin();
			fa[i] = vl[t - 1].Y;
			vl[t] = mp(a[i], i);
		}
	}
}
