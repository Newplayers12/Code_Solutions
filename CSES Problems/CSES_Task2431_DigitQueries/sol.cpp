
/*
author:		iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	untracked
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <string>
using namespace std;

#define u64 unsigned long long
const u64 K = 1.5e19;
u64 k;

u64 pow(u64 a, u64 b) {
	u64 r = 1;
	while (b--) r *= a;
	return r;
}

char calc() {
	// có `n == 9 * 10^(d-1)` số khác 0 có `d` chữ số
	for (u64 d=1, n=9, s=0; s < K; d++, n*=10) {
		// không bị tràn, đã chứng minh
		s += d*n;
		// `k` thuộc `(0:s]`
		// --> `k` là số có `d` chữ số
		if (k <= s) {
			// s trở thành vị trí của số đầu tiên có `d` chữ số trong dãy
			s -= d*n; s++;
			u64 delta_k = k-s;		// mục tiêu là số thứ `delta_k+1` (số đầu tiên là số thứ 1) có `d` chữ số
			u64 target = pow(10, d-1) + (delta_k / d);
			return to_string(target).at(delta_k%d);
		}
	}
	return '0';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q; cin >> q;
	while (q--) {
		cin >> k;
		cout << calc() << "\n";
	}
	return 0;
}
