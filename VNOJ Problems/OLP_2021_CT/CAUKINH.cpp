/*
    author:    Newplayers12
    created:   Saturday 05-11-2022  10:25:59
*/
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
#define all(X) X.begin(), X.end()

#define _Phuong ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int MOD = 1e9 + 7;
int main()
{
    _Phuong;
    int test;
    cin >> test;
    while(test--){
        string a, b;
        cin >> a >> b;
        int n = a.length();
        vector<int> dp(n);
        dp[0] = (a[0] == 'X') + (b[0] == 'X');
        for(int i = 1; i < n; ++i){
            if (a[i] == 'X') dp[i] = (dp[i] + dp[i - 1]) % MOD;
            if (b[i] == 'X') dp[i] = (dp[i] + dp[i - 1]) % MOD;
        }
        cout << dp[n - 1] << '\n';
    }
    return 0;
}