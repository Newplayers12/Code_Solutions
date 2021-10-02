/*
    author:    Newplayers12
    created:   Tuesday 21-09-2021  10:58:13
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x:a) cin >> x;
    for(int i = 0 ; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << (a[i] ^ a[j]) << ' ';
        }
        cout << '\n';
    }    
    return 0;
}