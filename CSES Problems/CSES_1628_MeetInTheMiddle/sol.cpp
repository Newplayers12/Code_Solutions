/*
    author:    Newplayers12
    created:   Tuesday 16-11-2021  21:47:49
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    fastio;
    int n;
    long long X;

    cin >> n;
    cin >> X;

    int half = n >> 1;
    int other = n - half;

    vector<int> a(half);
    vector<int> b(other);

    for(int &x:a) cin >> x;
    for(int &x:b) cin >> x;

    map<int, int> mp;

    for(int num = 0; num < (1<<half); ++num){
        long long sum = 0;
        for(int j = 0; j < half; ++j){
            if ((1<<j) & num){
                sum += a[j];
            }
        }

        if (sum <= X){
            mp[sum] ++;
        }
    }
    long long ans = 0;
    for(int num = 0; num < (1<<other); ++num){
        long long sum = 0;
        for(int j = 0; j < other; ++j){
            if ((1<<j) & num){
                sum += b[j];
            }
        }

        if (sum <= X){
            ans += mp[X - sum];
        }
    }
    cout << ans;
    return 0;
}