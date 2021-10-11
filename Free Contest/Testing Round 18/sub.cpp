
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	untracked
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+7, I = 1e4+7;
int n, arr[N];

int task1() {
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) res += arr[i];
	}
	//
	return res;
}

int kadane() {
	int best = -I, cr = 0;
	for (int i = 0; i < n; i++) {
		cr += arr[i];
		best = max(best, cr);
		if (cr < 0) cr = 0;
	}
	return best;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];
		// calc
		int biggest = *max_element(arr, arr+n);
		if (biggest <= 0) {
			cout << biggest << " " << biggest << endl;
		} else {
			cout << task1() << " " << kadane() << endl;
		}
	}
	// system("pause");
	return 0;
}
