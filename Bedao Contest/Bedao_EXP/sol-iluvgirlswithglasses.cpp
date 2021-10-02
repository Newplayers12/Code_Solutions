#include <iostream>
#include <math.h>
using namespace std;

#define ld long double

ld a, b, u, v;

ld epow(ld a, ld i) {
	if (a == 0) return 0;
	return a*pow((ld) 10, i);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q; cin >> q;
	while (q--) {
		cin >> a >> b >> u >> v;
		if (b > v) 
			b -= v, v = 0;
		else
			v -= b, b = 0;
		//
		ld x = epow(a, b);
		ld y = epow(u, v);
		if (x > y) {
			cout << "X > Y\n";
		} else if (x < y) {
			cout << "X < Y\n";
		} else {
			cout << "X = Y\n";
		}
	}
	return 0;
}
