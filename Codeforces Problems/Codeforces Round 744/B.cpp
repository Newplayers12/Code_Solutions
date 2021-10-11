
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	untracked
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct pack {
	int l, r, d;
};

const int N = 52;
int n, a[N];

void calc() {
	vector<pack> res; 
	vector<int> f(a, a+n), g(a, a+n);
	//
	for (int l = 0; l < n; l++) {
		int d = min_element(f.begin() + l, f.end()) - (f.begin() + l);
		if (d > 0) {
			res.push_back({l+1, n, d});
			for (int i = l, len = n-l; i < n; i++) {
				f[(i-l-d+len) % len + l] = g[i];
			}
			g = f;
		}
	}
	//
	cout << res.size() << "\n";
	for (pack &p: res) {
		cout << p.l << " " << p.r << " " << p.d << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		calc();
	}
	return 0;
}
