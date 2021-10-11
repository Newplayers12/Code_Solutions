
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	untracked
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * vars
 * */
const int N = 4003, M = 4e5+3;
int n, m, weight[N][N], max_weight[N][N];
ll mst_weight;
int* edges[M];
vector<int> mst_adj[N];


/**
 * dsu
 * */
vector<int> dsu_parent;

void dsu() {
	dsu_parent.resize(n);
	for (int i = 0; i < n; i++) dsu_parent[i] = i;
}

int dsu_find(int u) {
	if (dsu_parent[u] == u) return u;
	dsu_parent[u] = dsu_find(dsu_parent[u]);
	return dsu_parent[u];
}

bool dsu_join(int u, int v) {
	int p = dsu_find(u), q = dsu_find(v);
	if (p == q) return false;
	//
	if ((rand() % 2) & 1) {
		dsu_parent[p] = q;
	} else {
		dsu_parent[q] = p;
	}
	return true;
}


/**
 * kruskal
 * */
void kruskal() {
	for (int i = 0; i < m; i++) {
		int u = edges[i][0], v = edges[i][1];
		if (dsu_join(u, v)) {
			mst_adj[u].push_back(v);
			mst_adj[v].push_back(u);
			//
			weight[u][v] = edges[i][2];
			weight[v][u] = edges[i][2];
			mst_weight += edges[i][2];
		}
	}
}


/**
 * max edge
 * */
void max_edge_dfs(int src, int u, int p) {
	for (int v: mst_adj[u]) {
		if (v == p) continue;
		max_weight[src][v] = max(max_weight[src][u], weight[u][v]);
		max_edge_dfs(src, v, u);
	}
}


/**
 * drivers
 * */
int main() {
	// freopen("io\\inp.in", "r", stdin);
	// inp
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
    	int u, v, w; scanf("%d%d%d", &u, &v, &w);
        edges[i] = new int[3]{u-1, v-1, w};
    }
    sort(edges, edges + m, [](int *i, int *j){
    	return i[2] < j[2];
    });
    //
    dsu();
    kruskal();
    //
    for (int i = 0; i < n; i++) {
    	max_edge_dfs(i, i, i);
    }
    //
    int q; scanf("%d", &q);
    while (q--) {
    	int u, v; scanf("%d%d", &u, &v);
    	printf("%lld\n", mst_weight - max_weight[u-1][v-1]);
    }
    //
    return 0;
}

