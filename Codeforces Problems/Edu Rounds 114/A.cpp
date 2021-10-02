#include <bits/stdc++.h>

using namespace std;

#define ll long long

// ý tưởng là đề chỉ yêu cầu in n biểu thức khác nhau
// vậy thì chúng ta có thể in ra các biểu thức có k cặp lồng vào nhau -> cho k chạy từ 1 đến n.
// với các cặp thừa thì chỉ là in ra () cho đủ.

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