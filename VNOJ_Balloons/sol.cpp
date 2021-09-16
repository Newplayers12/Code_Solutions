#include <bits/stdc++.h>

using namespace std;
const int MXN = 2e5;
const int MXK = 200;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> dp(n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> dp[i];
        a[i] = dp[i];
    }
    for (int rounds = 2; rounds <= k; ++rounds)
    {
        vector<long long> tmp(n);
        deque<pair<long long, int>> q;
        // q.front() == Max in the range [max(0, i - M), i - 1]
        int head = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i >= rounds - 1)
                tmp[i] = a[i] * 1LL * (rounds) + (q.empty() ? 0 : q.front().first);

            while (q.empty() == false && q.front().second <= i - m)
            {
                q.pop_front();
            }
            while (q.empty() == false && dp[i] > q.back().first)
            {
                q.pop_back();
            }
            q.push_back({dp[i], i});
        }
        swap(tmp, dp);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}