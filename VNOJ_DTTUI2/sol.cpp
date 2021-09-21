/*
	author:    Newplayers12
	created:   Wednesday 15-09-2021  21:30:49
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0)
	
const int MXN = 1e3;
const int MXW = 1e4;
#define pii pair<int, int>
int dp[MXN + 5][MXW + 5];
int n, w;

const int INF = 1e9;

int main()
{
	fastio;
	memset(dp, 0, sizeof(dp));
	cin >> n >> w;
	vector<pair<int, int>> a;
	int num = 0;

	for (int i = 0; i < n; ++i)
	{
		int w, v, s;
		cin >> w >> v >> s;
		for (int j = 0; j < 10; ++j)
		{
			if (s >= (1 << j))
			{
				num++;
				a.push_back(pii((1 << j) * w, (1 << j) * v));
				s -= (1 << j);
			}
		}
		if (s)
		{
			a.push_back(pii(s * w, s * v));
			num++;
		}
	}

	// Sau đó thì knapsack 0/1 như thường.
	dp[0][0] = 0;
	for (int i = 1; i <= w; ++i)
		dp[0][i] = 0;

	for (int i = 1; i <= num; ++i)
	{
		for (int j = 0; j <= w; ++j)
		{
			if (j < a[i - 1].first)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i - 1].first] + a[i - 1].second);
			}
		}
	}
	cout << dp[num][w];
	return 0;
}
