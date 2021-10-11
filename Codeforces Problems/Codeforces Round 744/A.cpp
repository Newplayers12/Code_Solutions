
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	untracked
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n, c[3]; string s;

string calc() {
	memset(c, 0, sizeof(c));
	for (char &i: s) 
		c[i - 'A']++;
	if (c[1] == c[0] + c[2]) 
		return "YES";
	return "NO";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> s;
		n = s.length();
		cout << calc() << "\n";
	}
	return 0;
}
