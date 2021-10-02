#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

const int MXN = 300;

int dp[MXN + 1][MXN + 1]; // dp[x][y] = số dĩa ít nhất phải ăn để có được >= x Takoyaki và >= y Taiyaki

const int INF = 1e9;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }
    for(int i = 0; i <= x; ++i){
        for(int j = 0; j <= y; ++j){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(int item = 0; item < n; ++item){
        for(int i = x; i >= 0; --i){
            for(int j = y; j >= 0; --j){
                int first = max(i - a[item].first, 0);
                int second = max(j - a[item].second, 0);
                dp[i][j] = min(dp[i][j], dp[first][second] + 1);
            }
        }
    }
    
    cout << (dp[x][y]==INF ? -1 : dp[x][y]) << '\n';

}

