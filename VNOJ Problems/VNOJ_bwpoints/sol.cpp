
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Oct 07 20:34:08 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define pi pair<int, bool>
#define st first
#define nd second

const int N = 2e5+7;
int n, k;
pi a[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].st;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i+n].st;
		a[i+n].nd = 1;
	}
	n <<= 1;
	sort(a, a+n);
	//
	bool binding = false;
	bool bind_typ = false;
	for (int i = 0; i < n; i++) {
		if (!binding) {
			binding = true;
			bind_typ = a[i].nd;
		} else {
			if (a[i].nd != bind_typ) {
				k++;
				binding = false;
			}
		}
	}
	cout << k << "\n";
	return 0;
}

