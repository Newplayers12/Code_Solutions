#include <iostream>
#include <algorithm>
using namespace std;

#define pi pair<int, bool>
#define st first
#define nd second

const int N = 1e6+7, I = 2e9+7;
int n, m, c1, c2;
pi a[N];


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//
	cin >> n >> m >> c1 >> c2;
	for (int i = 0; i < n; i++) {
		cin >> a[i].st; a[i].nd = 0;
	}
	for (int i = 0; i < m; i++) {
		cin >> a[i+n].st; a[i+n].nd = 1;
	}
	n += m;
	sort(a, a+n, [](pi &i, pi &j){
		return i.st < j.st;
	});
	//
	int i = 1, pre[2];
	for (; i < n; i++) {
		if (a[i].nd != a[i-1].nd) break;
	}
	pre[a[i].nd] = a[i].st; pre[a[i-1].nd] = a[i-1].st;
	//
	int res = I, cnt = 0;
	for (; i < n; i++) {
		int d = a[i].st - pre[!a[i].nd];
		if (d < res) {
			res = d;
			cnt = 1;
		} else if (d == res) {
			cnt++;
		}
		pre[a[i].nd] = a[i].st;
	}
	//
	cout << res + abs(c1 - c2) << " " << cnt << "\n";
	return 0;
}
