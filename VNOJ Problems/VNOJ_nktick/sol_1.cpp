#include <bits/stdc++.h>
using namespace std;
int n;
int T[60005], R[60005];
int dp[60005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; cin >> T[i++]);
    for(int i = 1; i < n; cin >> R[i++]);
    dp[1] = T[1];
    dp[2] = min(R[1], T[1] + T[2]);
    for(int i = 3; i <= n; ++i){
        dp[i] = min(min(T[i-1] + T[i] , R[i - 1]) + dp[i - 2], R[i-2] + T[i] + dp[i-3]);
    }
    cout << dp[n];
    return 0;
}