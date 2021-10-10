/*        
                                                          _ooOoo_
                                                         o8888888o
                                                         88" . "88
                                                         (| -_- |)
                                                          O\ = /O
                                                      ____/`---'\____
                                                    .   ' \\| |// `.
                                                     / \\||| : |||// \
                                                   / _||||| -:- |||||- \
                                                     | | \\\ - /// | |
                                                   | \_| ''\---/'' | |
                                                    \ .-\__ `-` ___/-. /
                                                 ___`. .' /--.--\ `. . __
                                              ."" '< `.___\_<|>_/___.' >'"".
                                             | | : `- \`.;`\ _ /`;.`/ - ` : | |
                                               \ \ `-. \_ __\ /__ _/ .-` / /
                                       ======`-.____`-.___\_____/___.-`____.-'======
                                                          `=---='

                                       .............................................
                                              Buddha bless, never bug
*/
/*
    author:    Newplayers12
    created:   Tuesday 05-10-2021  20:59:21
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    fastio;
    int test;
    cin >> test;
    while(test--){
        int n, h;
        cin >> n >> h;
        vector<int> a(n);
        for(int &x:a) cin >> x;
        sort(a.rbegin(), a.rend());
        int ans = h/(a[0] + a[1]);
        ans <<= 1;
        h %= (a[0] + a[1]);
        if (h == 0){
            cout << ans;
        } else if (h <= a[0]){
            cout << ans + 1;
        } else cout << ans + 2;
        cout << '\n';
    }
    return 0;
}