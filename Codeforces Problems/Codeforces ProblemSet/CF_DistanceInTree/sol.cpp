
/*
author:		iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	untracked
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <vector>
using namespace std;

#define u64 unsigned long long
#define u16 unsigned short

const u16 N = 5e4+7, K = 502;
u16 n, k, dp[N][K];
u64 res;
vector<u16> adj[N];

void dfs(int u, int p) {
	for (u16 &v: adj[u]) if (v != p) {
		dfs(v, u);
		for (int i = 0; i < k; i++) {
			res += dp[u][i] * dp[v][k-i-1];
			dp[u][i] += dp[v][i-1];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < n; i++) 
		dp[i][0] = 1;
	dfs(0, -1);
	//
	cout << res << "\n";
	return 0;
}
