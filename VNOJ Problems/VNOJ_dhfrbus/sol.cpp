
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	untracked
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <climits>
#include <queue>
#include <vector>
using namespace std;

#define u64 unsigned long long
const int N = 1e5+7, M = 1e5+7, K = 6;

struct node {
	int u, k;
	u64 c;	

	// lừa priority queue
	bool operator < (const node &i) const {
		return c > i.c;
	}

	//
	static node mknode(int u, int k, u64 c) {
		node n; 
		n.u = u; n.k = k; n.c = c;
		return n;
	}
};

/**
 * 
 * */
int n, m, k, s, t;
vector<node> adj[N];
vector<u64> d[K];

void dijkstra() {
	for (int i = 0; i <= k; i++)
		d[i].resize(n, ULONG_LONG_MAX);
	d[0][s] = 0;
	priority_queue<node, vector<node>> q;
	q.push(node::mknode(s, 0, 0));
	//
	while (q.size()) {
		node a = q.top(); q.pop();
		//
		for (node &b: adj[a.u]) {
			u64 dist = a.c + b.c;
			if (dist < d[a.k][b.u]) {
				d[a.k][b.u] = dist;
				q.push(node::mknode(b.u, a.k, dist));
			}
			// free ship 2 chiều
			if (a.k < k) {
				if (a.c < d[a.k+1][b.u]) {
					d[a.k+1][b.u] = a.c;
					q.push(node::mknode(b.u, a.k+1, a.c));
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k >> s >> t;
	s--, t--;
	for (int i = 0, u, v, c; i < m; i++) {
		cin >> u >> v >> c;
		u--, v--;
		adj[u].push_back(node::mknode(v, 0, c));
		adj[v].push_back(node::mknode(u, 0, c));
	}
	//
	dijkstra();
	u64 res = ULONG_LONG_MAX;
	for (int i = 0; i <= k; i++)
		res = min(res, d[i][t]);
	cout << res << "\n";
	return 0;
}
