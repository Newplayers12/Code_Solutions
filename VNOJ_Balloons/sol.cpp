/*
    author:    Newplayers12
    created:   Wednesday 08-09-2021  18:10:53
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
    cout << n;
    vector<int> a(n);
    for(int &x:a) cin >> x;
    for(int x:a) cout << x << ' ';
    return 0;
}