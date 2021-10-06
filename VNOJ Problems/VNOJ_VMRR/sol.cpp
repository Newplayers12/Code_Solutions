/*
    author:    Newplayers12
    created:   Wednesday 06-10-2021  19:09:20
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int dem[300];

int main()
{
    fastio;
    memset(dem, 0, sizeof(dem));
    string s;
    getline(cin, s);
    long long ans = 0;
    unsigned char X, Y;
    cin >> X >> Y;
    for(int i = 0; i < (int) s.length(); ++i){
        unsigned char num = s[i];
        if (num == Y){
            ans += dem[X];
        }
        if (num == X){
            dem[X] ++;
        }
    }
    cout << ans;
    return 0;
}