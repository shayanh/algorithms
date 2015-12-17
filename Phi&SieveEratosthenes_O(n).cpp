#include <iostream>
#include <vector>
using namespace std;

const int N = 1000 * 1000;

vector <int> pr;
int lp[N], phi[N];

void Sieve(int n){
	for (int i = 2;i < n; ++i) {
		if (lp[i] == 0)
			lp[i] = i,
			pr.push_back(i);

		for (int j = 0;j < pr.size() && pr[j] <= lp[i] && i * pr[j] < n; ++j)
			lp[i * pr[j]] = pr[j];
	}
}

void Find_Phi(int n) {
	phi[1] = 1;
	for(int i = 2;i < n;++i) {
		if(lp[i] == i)
			phi[i] = i - 1;
		else {
			phi[i] = phi[lp[i]] * phi[(i / lp[i])];
			if(lp[i / lp[i]] == lp[i])
				phi[i] *= lp[i], phi[i] /= (lp[i] - 1)
		}
	}
}
