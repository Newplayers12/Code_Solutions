#include <bits/stdc++.h>
using namespace std;
string repeat(string s, int n){
    string s1 = s;
    if(n == 0){
        return "";
    }
    for (int i=1; i<n;i++)
        s += s1; 
    return s;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i){
            string main = repeat("()", (i));
            string sub =  repeat("(", (n - i)) +  repeat(")", (n - i));
            cout << main  + sub << "\n";
        }
    }
    return 0;
}