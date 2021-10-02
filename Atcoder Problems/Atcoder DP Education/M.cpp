#include <iostream>
using namespace std;

#define ll long long

const ll N = 102, K = 1e5+7, R = 1e9+7;
ll n, a, k, p[K], dp[N][K];
// p[i][j] == số cách chia j viên kẹo cho i đứa trẻ đầu tiên

ll get(int i) {
	if (i < 0) return 0;
	return p[i];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	dp[0][0] = 1;
	//
	for (ll i = 1; i <= n; i++) {
		cin >> a;
		p[0] = dp[i-1][0];
		for (int j = 1; j <= k; j++)
			p[j] = (p[j-1] + dp[i-1][j]) % R;
		for (int j = 0; j <= k; j++)
			dp[i][j] = (p[j] - get(j-a-1) + R) % R;
	}
	cout << dp[n][k] << "\n";
	return 0;
}
