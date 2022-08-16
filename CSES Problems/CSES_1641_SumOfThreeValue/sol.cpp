/*
    author:    Newplayers12
    created:   Wednesday 17-11-2021  13:30:07
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    fastio;
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int &x:a) cin >> x;
    for(int i = 0; i < n - 2; ++i){
        map<int, bool> mp;
        for(int j = i + 1; j < n; ++j){
            if (j == i + 1){
                mp[a[j]] = true;
            }
            int other = x - a[i] - a[j];
            if mp[other]
        }
    }
    return 0;
}