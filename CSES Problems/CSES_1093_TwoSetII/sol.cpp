/*
    author:    Newplayers12
    created:   Wednesday 17-11-2021  12:57:22
*/
#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
 
const int MXN = 125255;
const int mod = 1e9 + 7;
int cnt[MXN];
 
int lt(int x, int y){
    int res = 1;
    x %= mod;
    while (y){
        if (y & 1) {
            res = (res * 1LL * x) % mod;
        }
        x = (x * 1LL * x) % mod;
        y >>= 1;
    }
    return res;
}
 
int main()
{
    fastio;
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    cnt[0] = 1;
    if (sum & 1) {
        cout << 0;
    } else {
        sum >>= 1;
        for(int i = 1; i <= n; ++i){
            for(int money = sum; money >= i; money --){
                cnt[money] = (cnt[money] + cnt[money - i]) % mod;
            }
        }
        cout << (cnt[sum] * 1LL * lt(2, mod - 2)) % mod;
    }
 
    return 0;
}