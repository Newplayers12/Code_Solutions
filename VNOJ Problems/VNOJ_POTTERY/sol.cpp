/*
    author:    Newplayers12
    created:   Friday 10-09-2021  11:02:28
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0)

int main()
{
	fastio;
	int T;
	cin >> T;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;
	int m;
	cin >> m;
	vector<int> b(m);
	for (int &x : b)
		cin >> x;

	int low = 0;
	int high = T;
	long long ans = 0;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		long long m1 = 0;
		for (int x : a)
		{
			m1 += mid / x;
		}
		long long m2 = 0;
		for (int x : b)
		{
			m2 += (T - mid) / x;
		}
		ans = max(ans, min(m1, m2));
		if (m1 >= m2)
		{

			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	cout << ans;
	return 0;
}