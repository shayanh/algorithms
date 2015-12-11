#include <iostream>
#include <vector>
using namespace std;

const int N = 1000 * 1000;

vector <int> pr;
int lp[N], phi[N];

void sieve_new(int n){
	for (int i = 2;i < n; ++i) {
		if (lp[i] == 0)
			lp[i] = i,
			pr.push_back(i);

		for (int j = 0;j < pr.size() && pr[j] <= lp[i] && i * pr[j] < n; ++j)
			lp[i * pr[j]] = pr[j];
	}
}

void find_phi(int n) {
	phi[1] = 1;
	for(int i = 2;i <= n;++i)
		phi[i] = (lp[i] - 1) * phi[(i / lp[i])];
}
