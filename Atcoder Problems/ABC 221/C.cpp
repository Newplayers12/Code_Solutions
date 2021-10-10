/*
    author:    Newplayers12
    created:   Wednesday 06-10-2021  18:30:57
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    fastio;
    string s;
    cin >> s;
    int n = (int) s.length();
    sort(s.rbegin(), s.rend());
    long long ans = 0;
    for(int num = 1; num < (1<<n); ++num){
        bitset<11> f(num);
        long long left, right;
        left = right = 0LL;
        for(int i = 0; i < n; ++i){
            if (f[i]){
                left = left * 10 + (s[i] - '0') * 1LL;
            } else {
                right = right * 10 + (s[i] - '0') * 1LL;
            }
        }
        ans = max(ans, left * right);
    }
    cout << ans;
    return 0;
}