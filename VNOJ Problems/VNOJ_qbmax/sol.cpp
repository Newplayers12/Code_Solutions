
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

const int N = 107, I = 1e9+7;
int m, n, arr[N][N], dp[N][N];

int main() {
	// inp
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) cin >> arr[i][j];
	}
	// init dp
	for (int i = 0; i <= n; i++) {
		dp[0][i] = -I;
		dp[m+1][i] = -I;
	}
	// calc
	// duyệt theo cột
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= m; i++) {
			int pre[3] = {dp[i-1][j-1], dp[i][j-1], dp[i+1][j-1]};
			dp[i][j] = arr[i][j] + *max_element(pre, pre+3);
		}
	}
	//
	int res = -I;
	for (int i = 1; i <= m; i++) res = max(res, dp[i][n]);
	cout << res << endl;
	system("pause");
	return 0;
}
