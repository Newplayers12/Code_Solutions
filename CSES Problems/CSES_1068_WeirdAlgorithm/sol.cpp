/*
    author:    Newplayers12
    created:   Tuesday 16-11-2021  19:38:03
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    fastio;
    long long n;
    cin >> n;
    while (n > 1){
        cout << n << ' ';
        if (n&1) {
            n = 3*n + 1;
        } else{
            n >>= 1;
        }
    }
    cout << 1;
    return 0;
}