#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 2e5+7;
int n, k, a[N], c[N];
vector<int> loc[N];

void getinp() {
	for (int i = 0, v; i < n; i++) {
		cin >> v;
		if (loc[v].size() != c[v]) 
			loc[v].clear();	// init trick
		if (c[v] < k)
			loc[v].push_back(i), c[v]++;
	}
}

void calc() {
	int m = 0, cr = 0;
	for (int v = 0; v < n; v++)
		m += c[v];
	//
	m = m/k * k;
	for (int v = 0; v < n; v++) if (c[v] > 0) {
		for (int &i: loc[v]) {
			a[i] = ++cr;
			cr %= k;
			if (--m == 0) return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> k;
		memset(a, 0, sizeof(a[0])*n);
		memset(c, 0, sizeof(c[0])*n);
		//
		getinp();
		calc();
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << "\n";
	}
	return 0;
}
