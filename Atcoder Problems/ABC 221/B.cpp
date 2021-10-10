/*
    author:    Newplayers12
    created:   Wednesday 06-10-2021  18:26:12
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    fastio;
    string s;
    cin >> s;
    string t;
    cin >> t;
    int n = (int) s.length();
    for(int i = 0; i < n - 1; ++i){
        if (t[i] != s[i] && s[i+1] != t[i + 1]){
            swap(t[i], t[i + 1]);
            break;
        }
    }
    if (s == t){
        cout << "Yes";
    } else cout << "No";
    return 0;
}