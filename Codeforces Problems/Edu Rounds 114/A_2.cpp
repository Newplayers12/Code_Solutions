
/*
author:		iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	untracked
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
using namespace std;

int n, len;

void calc() {
	string s = "";
	len = n<<1;
	for (int i = 1; i <= n; i++)
		s += "()";
	for (int i = 1; i <= n; i++) {
		cout << s << "\n";
		// dời ngoặc cuối vào trong
		s = s.substr(0, i) + s.substr(len-2, 2) + s.substr(i, len-2-i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		calc();
	}
	return 0;
}
