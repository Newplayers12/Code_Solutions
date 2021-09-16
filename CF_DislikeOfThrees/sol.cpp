/*
    author:    Newplayers12
    created:   Thursday 16-09-2021  10:31:03
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

bool check(int x){
    if (x % 3 == 0){
        return false;
    }
    if ((x%10) == 3){
        return false;
    }
    return true;
}

int main()
{
    fastio;
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int cnt = 0;
        int dem = 0;
        do {
            cnt++;
            if (check(cnt)) dem++;
        } while(dem < n);
        cout << cnt << '\n';
    }
    return 0;
}