
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct 10 22:18:34 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
using namespace std;

#define u32 unsigned int
#define u64 unsigned long long
const u64 R = 1e9+7;
u32 n, k;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> k;
		u64 pow = 1, res = 0;
		for (int i = 0; i < 31; i++) {
			if (k>>i&1) res = (res + pow) % R;
			pow = pow*n % R;
		}
		cout << res << "\n";
	}
	return 0;
}

