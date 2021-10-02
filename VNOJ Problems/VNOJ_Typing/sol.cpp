/*
    author:    Newplayers12
    created:   Thursday 09-09-2021  12:31:20
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)

const long long mod = 1e9 + 7;

int main()
{
    fastio;
    string s;
    cin >> s;
    int len = 0;
    char last = s[0];
    long long ans = 1;
    for (int i = 0; i < (int)s.length(); ++i)
    {
        if (s[i] == last)
        {
            len++;
        }
        else
        {
            ans = (ans * len) % mod;
            len = 1;
            last = s[i];
        }
    }
    ans = (ans * len) % mod;
    cout << ans;
    return 0;
}