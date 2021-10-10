#include <bits/stdc++.h>
using namespace std;


long long dp[105][100005];
const long modu = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    int child[n + 1];
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; ++i){
        cin >> child[i];
        dp[i][0] = 1;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i){
        long long sum = dp[i - 1][0];
        queue<int> index_sum;
        index_sum.push(dp[i - 1][0]);
        for(int j = 1; j <= k; ++j){
                sum += dp[i - 1][j] % modu;
                index_sum.push(dp[i - 1][j]);
                if(index_sum.size() - 1 > child[i]){
                    sum -= index_sum.front() % modu;
                    index_sum.pop();
                }
                dp[i][j] = sum % modu;
        }
    }
    cout << dp[n][k];
    return 0;
}