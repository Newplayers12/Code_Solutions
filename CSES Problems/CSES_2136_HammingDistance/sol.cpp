/*
    author:    Newplayers12
    created:   Tuesday 16-11-2021  22:07:05
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    fastio;
    int n, k;
    cin >> n >> k;
    vector<bitset<30>> a(n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < k; ++j){
            char c;
            cin >> c;
            if (c == '1') a[i][j] = 1; else a[i][j] = 0;
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i < n - 1; ++i){
        for(int j = i + 1; j < n; ++j){
            bitset<30> temp = a[i] ^ a[j];
            
            ans = min(ans, (int) temp.count());
        }
    }
    cout << ans;
    return 0;
}