#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

ll max(ll a, ll b) {
	if (a > b) return a;
	return b;
}

ll a, b, c, m;

bool calc() {
	ll maxm = max(0, a-1) + max(0, b-1) + max(0, c-1);
	ll minm[3] = {a-b-c-1, b-a-c-1, c-a-b-1};
	return *max_element(minm, minm+3) <= m &&
		   m <= maxm;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> a >> b >> c >> m;
		if (calc()) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}
