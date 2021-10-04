/*
    author:    Newplayers12
    created:   Monday 04-10-2021  22:44:45
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    fastio;
    string s;
    cin >> s;
    int test;
    cin >> test;
    int id = 0;
    while(test--){
        id++;
        string t;
        cin >> t;
        if (t.length() == s.length()){
            int dem = 0;
            for(int i = 0; i < s.length(); ++i){
                if (s[i] != t[i]) dem++;
                if (dem > 2){
                    break;
                }
            }
            if (dem>2){
                continue;
            }
            cout << id << ' ';
        }
    }
    return 0;
}