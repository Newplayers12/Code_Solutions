
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

struct edge {
	int u, v, c;
};

const int N = 1e4+7, M = 1e5+7;
int n, m, s;
edge arr[M];

/**
 * dsu
 * */
int p[N];

int find(int u) {
	if (p[u] == u) return u;
	p[u] = find(p[u]);
	return p[u];
}

bool join(int u, int v) {
	int a = find(u), b = find(v);
	if (a == b) 
		return false;
	//
	p[a] = b;
	return true;
}


/**
 *
 * */
int calc() {
	int res = 0;
	for (int i = 0; i < m; i++) {
		if (join(arr[i].u, arr[i].v)) {
			res += arr[i].c;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i].u >> arr[i].v >> arr[i].c;
		s += arr[i].c;
	}
	//
	for (int i = 1; i <= n; i++) p[i] = i;
	sort(arr, arr+m, [](edge &i, edge &j){
		return i.c > j.c;
	});
	//
	cout << s - calc() << endl;
	return 0;
}

