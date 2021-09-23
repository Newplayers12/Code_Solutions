#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < i; ++j){
                cout << '(';
            }
            for(int j = 0; j < i; ++j){
                cout << ')';
            }
            for(int j = 0; j < n - i; ++j){
                cout << "()";
            }
            cout << '\n';
        }
    }

    return 0;
}