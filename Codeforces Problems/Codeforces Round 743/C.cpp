
/*
author:		iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	untracked
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

/*
một cách làm đến từ editorial
rất bá đạo
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define pi pair<int, bool>
#define st first
#define nd second

const int N = 2e5+7;
int n, dp[N];
vector<pi> adj[N];

bool dfs(int u, int &res, vector<bool> &visited, vector<bool> &st) {
	visited[u] = true;
	st[u] = true;
	for (pi &p: adj[u]) {
		int v = p.st, c = p.nd;
		//
		if (!visited[v]) {
			if (!dfs(v, res, visited, st)) return false;
		} else if (st[v]) {
			// nếu đỉnh đã có trong recursion stack
			// --> đồ thị có chu trình
			return false;
		}
		dp[u] = max(dp[u], dp[v] + c);
	}
	st[u] = false;	// xóa `u` ra khỏi recursion stack
	return true;
}

int calc() {
	int res = 0;
	memset(dp, 0, sizeof(dp[0])*n);
	vector<bool> visited(n, false);
	//
	for (int i = 0; i < n; i++) 
	if (!visited[i]) {
		vector<bool> st(n, false);
		// có chu trình --> không có cách đọc
		if (!dfs(i, res, visited, st)) return -1;
	}
	return 1 + *max_element(dp, dp+n);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		//
		for (int u = 0, k; u < n; u++) {
			cin >> k;
			adj[u].resize(k);
			//
			for (int i = 0, v; i < k; i++) {
				cin >> v;
				adj[u][i] = {--v, u > v ? 0: 1};
			}
		}
		cout << calc() << "\n";
	}
	return 0;
}
