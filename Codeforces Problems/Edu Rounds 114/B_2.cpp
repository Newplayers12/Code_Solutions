#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while(q--){
        int a, b, c, m;
        cin >> a >> b >> c >>m;
        int maxx = (a - 1) * (a >= 2) + (b - 1) * (b >= 2) + (c - 1) * (c >= 2);
        int minn = max(a - b - c, 0) + max(b - a - c, 0) + max(c - a - b, 0);
        minn = (minn - 1) * (minn >= 2);
        if(maxx >= m && m >= minn){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
 
    return 0;
}