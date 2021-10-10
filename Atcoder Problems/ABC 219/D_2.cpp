#include <bits/stdc++.h>
using namespace std;
 
int x, y;
int dp[305][305][305];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    cin >> x >> y;
    vector<pair<int, int>> lunch(n + 1);
    memset(dp, 0x3f3f3f3f, sizeof dp);
    for(int i=0;i<=n;i++)
        dp[i][0][0]=0;
    for(int i = 1; i <= n; ++i){
        int a, b;
        cin >> a >> b;
        for(int j = 0; j <= x; ++j){
            for(int z = 0; z <= y; ++z){
                dp[i][j][z] = min(dp[i - 1][max(j - a, 0)][max(z - b, 0)] + 1, dp[i - 1][j][z]);
            }
        }
    }
    if(dp[n][x][y] > n){
        cout << -1;
        return 0;
    }
    cout << dp[n][x][y];
    return 0;
}