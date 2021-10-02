#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin >> test;
    while(test--){
        long long x, y;
        string _a, _b;
        cin >> x >> _a;
        cin >> y >> _b;

        if (x == 0 && y == 0){
            cout << "X = Y\n";
            continue;
        } else
        if (x == 0){
            cout << "X < Y\n";
            continue;
        } else
        if (y == 0){
            cout << "X > Y\n";
            continue;
        }
        long long a = stoll(_a);
        long long b = stoll(_b);
        long long minn = min(a, b);
        a -= minn;
        b -= minn;
        for(int i = 0; i < a; ++i) x *= 10;
        for(int i = 0; i < b; ++i) y *= 10;

        if (x < y){
            cout << "X < Y";
        } else if (x > y)
            cout << "X > Y";
        else cout << "X = Y";
        cout << '\n';
    }

    return 0;
}
