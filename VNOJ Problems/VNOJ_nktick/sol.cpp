
/*
author:		iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Oct 02 18:28:31 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
using namespace std;

const int N = 6e4+7, I = 1e9+7;
// dp[0]: bình thường
// dp[1]: mua giúp
// dp[2]: được mua giúp
int n, t[N], r[N], dp[3][N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> t[i];
	for (int i = 0; i < n-1; i++)
		cin >> r[i];
	//
	dp[0][0] = t[0];
	dp[1][0] = r[0];
	dp[2][0] = I;
	for (int i = 1; i < n; i++) {
		// khi người trước mua 1 vé / không mua vé nào
		// --> người này có thể tự mua hoặc mua giúp người khác
		dp[0][i] = min(dp[0][i-1], dp[2][i-1]) + t[i];
		dp[1][i] = min(dp[0][i-1], dp[2][i-1]) + r[i];
		// vé của người này được mua bởi người trước đó
		dp[2][i] = dp[1][i-1];
	}
	//
	cout << min(dp[0][n-1], dp[2][n-1]) << "\n";
	return 0;
}

