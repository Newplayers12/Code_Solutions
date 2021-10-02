/*
    author:    Newplayers12
    created:   Saturday 02-10-2021  11:25:28
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    fastio;
    long long k;
    cin >> k;
    string a;
    string b;
    cin >> a >> b;
    long long NumA = 0;
    long long NumB = 0;
    long long top = 1;
    for(int i = a.length() - 1; i >= 0; --i){
        NumA += (long long)(a[i] - '0') * top;
        top *= k;
    }
    top = 1;
    for(int i = b.length() - 1; i >= 0; --i){
        NumB += (long long)(b[i] - '0') * top;
        top *= k;
    }
    cout << NumA * NumB << '\n';
    return 0;
}