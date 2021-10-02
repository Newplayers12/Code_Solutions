/*
    author:    Newplayers12
    created:   Thursday 09-09-2021  17:18:09
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9 + 7;

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<vector<int>> can(n, vector<int>(n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> can[i][j];
        }
    }
    vector<int> dp[25];
    for(int i = 0; i < 25; ++i){
        dp[i].assign((1<<n), 0);
    }


    dp[0][0] = 1; // trường hợp base, không xét nam nào và bitmask rỗng sẽ coi như là một cách.
    for(int i = 1; i <= n; ++i){
        for(int m = 0; m < (1<<n); ++m){
            int cnt = __builtin_popcount(m);
            if (cnt >= i) continue; // số lượng gái được ghép cặp phải < chỉ số nam đang xét.
            for(int girl = 0; girl < n; ++girl){
                if (can[i - 1][girl] && !(m & (1 << girl))){
                    int &res = dp[i][m ^ (1<<girl)];
                    res = (res + dp[i-1][m]) % mod;
                }
            }
        }
    }

    // bài này có thể cải tiến hơn như code của Errichto.
    cout << dp[n][(1<<n) - 1];
    return 0;
}