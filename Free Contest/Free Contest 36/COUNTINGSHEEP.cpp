/*
    author:    Newplayers12
    created:   Wednesday 06-10-2021  19:02:44
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int cnt[11];

void update(long long x){
    while (x){
        cnt[x%10]++;
        x /= 10;
    }
}

bool check(){
    for(int i = 0; i < 10; ++i){
        if (cnt[i] == 0) return false;
    }
    return true;
}

int main()
{
    fastio;
    int test;
    cin >> test;
    while(test--){
        long long n;
        cin >> n;
        if (n == 0){
            cout << "Awake!";
        } else {
            int dem = 1;
            memset(cnt, 0, sizeof(cnt));
            long long tmp = n;
            update(tmp);
            while(!check()){
                dem++;
                tmp += n;
                update(tmp);
            }
            cout << n * dem;
        }
        cout << '\n';
    }
    return 0;
}