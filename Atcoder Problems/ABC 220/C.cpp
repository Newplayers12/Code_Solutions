/*
    author:    Newplayers12
    created:   Saturday 02-10-2021  13:22:17
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &x:a) cin >> x;
    long long Sum = accumulate(a.begin(), a.end(), 0LL);
    long long X;
    cin >> X;
    long long ans = X / Sum;
    ans = ans * n;
    X %= Sum;
    for(int i = 0; i < n; ++i){
        if (X >= a[i]){
            X -= a[i];
            ans++;
        } else {
            break;
        }
    }
    cout << ans + 1 << '\n';
    return 0;
}