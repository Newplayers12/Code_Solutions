/*
    author:    Newplayers12
    created:   Thursday 27-10-2022  11:54:52
*/
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }

#define _Phuong ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    _Phuong;
    int n;
    cin >> n;
    int prev = -1;
    long long ans = 1;
    int cnt = 0;
    for(int i = 0 ; i < n; ++i){
        int u;
        cin >> u;
        cnt += u;
        if (u) {
            if (prev == -1) prev = i;
            else ans *= (i - prev);
            prev = i;
        }
    }
    if (cnt)
    cout << ans; else cout << 0;
    return 0;
}