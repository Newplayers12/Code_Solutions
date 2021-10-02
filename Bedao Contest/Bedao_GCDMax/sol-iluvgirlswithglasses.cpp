#include <iostream>
using namespace std;

int __gcd(int a, int b) {
	if (b == 0) return a;
	return __gcd(b, a % b);
}

int gcd(int a, int b) {
	if (b > a) swap(a, b);
	return __gcd(a, b);
}

/**
 * 
 * */
const int N = 1e6+7, I = 1e9;
int n, a[N], p[N], s[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	if (n == 1) {
		cout << I << "\n";
		return 0;
	}
	//
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[i] = gcd(a[i], p[i-1]);
	}
	for (int i = n; i >= 1; i--) {
		s[i] = gcd(a[i], s[i+1]);
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res = max(res, gcd(p[i-1], s[i+1]));
	}
	cout << res << "\n";
	return 0;
}
