
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	untracked
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * vars
 * */
const int N = 1e5+7, M = 1e5+7;
int n, m;
vector<int> adj[N];
// visited[i] == true if the city has already been visited
// group[i] == group[j] --> city i can travel to city j
// linked[i] indicate how many cities can be traversed from i (including i) 
int visited[N], group[N], linked[N];

/**
 * perf
 * */
void bfs(int src) {
	int cr_linked = 1;
	vector<int> f = {src};
	queue<int> q; q.push(src);
	visited[src] = true;
	//
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v: adj[u]) {
			if (!visited[v]) {
				visited[v] = true; 
				cr_linked++;
				f.push_back(v);
				q.push(v);
			}
		}
	}
	//
	for (int i: f) {
		group[i] = src;
		linked[i] = cr_linked;
	}
}

void calc() {
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			bfs(i);
		}
	}
}

/**
 * drivers
 * */
int main() {
	// inp
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// calc
	calc();
	int max_v = 0;
	for (int i = 0; i < n; i++) {
		if (group[i] != 0 && linked[i] > max_v) max_v = linked[i];
	}
	cout << linked[0] + max_v << endl;
	// 
	system("pause");
	return 0;
}
