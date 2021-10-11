
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	untracked
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define pi pair<int, int>
#define st first
#define nd second

const int N = 2e5+7;
int n; 

void calc(priority_queue<pi> &q) {
	vector<pi> v;
	//
	while (q.size() >= 2) {
		pi a = q.top(); q.pop();
		pi b = q.top(); q.pop();
		v.push_back({a.nd, b.nd});
		a.st--; 
		b.st--;
		if (a.st > 0) q.push(a);
		if (b.st > 0) q.push(b);
	}
	//
	cout << "\n";
	cout << v.size() << "\n";
	for (pi &i: v) {
		cout << i.st << " " << i.nd << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		priority_queue<pi> q;
		cin >> n;
		for (int i = 0, v; i < n; i++) {
			cin >> v;
			if (v > 0)
				q.push({v, i+1});
		}
		calc(q);
	}
	return 0;
}
