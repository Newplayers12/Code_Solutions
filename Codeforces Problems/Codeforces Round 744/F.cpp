
/*
author:		iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	untracked
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/


/*
dp
time complexity: 	O(n)
space complexity: 	O(n)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e6+7;
int n, d, dp[N];
vector<bool> a;

void recursion(int i, const int root, bool check) {
	if (check && i == root) return;
	if (!a[i]) return;
	//
	int j = (i+d)%n;
	recursion(j, root, true);
	if (!a[j]) {
		a[i] = 0;
		dp[i] = dp[j]+1;
	}
}

int calc() {
	for (int i = 0; i < n; i++) if (a[i]) {
		recursion(i, i, false);
		if (a[i]) return -1;
	}
	return *max_element(dp, dp+n);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> d;
		a.resize(n);
		memset(dp, 0, n*sizeof(dp[0]));
		//
		for (int i = 0, v; i < n; i++) {
			cin >> v;
			a[i] = v;
		}
		cout << calc() << "\n";
	}
	return 0;
}
