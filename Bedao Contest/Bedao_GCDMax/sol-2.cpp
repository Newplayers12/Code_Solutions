#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int test;
    test = 1;
    while(test--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> pre(n);
        vector<int> suf(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            if (i){
                pre[i] = __gcd(a[i], pre[i-1]);
            } else pre[i] = a[i];
        }
        if (n == 1) {
            cout << int(1e9);
            continue;
        }
        suf[n - 1] = a[n-1];

        for(int i = n - 2; i >= 0 ; --i){
            suf[i] = __gcd(suf[i+1], a[i]);
        }
        int maxx = max(pre[n - 2], suf[1]);
        for(int i = 1; i <= n - 2; ++i){
            maxx = max(__gcd(pre[i-1], suf[i+1]), maxx);
        }
        cout << maxx << '\n';
    }

    return 0;
}
