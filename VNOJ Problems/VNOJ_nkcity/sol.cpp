
/*
author:		iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	untracked
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e3+7, M = 1e4+7;
int n, m, p[N];
int* a[M];

int find(int u) {
	if (p[u] == u) return u;
	p[u] = find(p[u]);
	return p[u];
}

bool join(int u, int v) {
	int a = find(u), b = find(v);
	if (a == b) return false;
	p[a] = b;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		p[i] = i;
	for (int i = 0, u, v, t; i < m; i++) {
		cin >> u >> v >> t;
		a[i] = new int[3]{--u, --v, t};
	}
	sort(a, a+m, [](int* i, int* j){
		return i[2] < j[2];
	});
	int maxx;
	for (int i = 0; i < m; i++) {
		int u = a[i][0], v = a[i][1], t = a[i][2];
		if (join(u, v)) {
			maxx = t;
		}
	}
	cout << maxx << "\n";
	return 0;
}
