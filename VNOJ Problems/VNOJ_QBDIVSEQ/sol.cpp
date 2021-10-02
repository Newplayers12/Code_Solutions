/*
    author:    Newplayers12
    created:   Tuesday 21-09-2021  21:02:46
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<int> res;
    for(int i = 0; i < n; ++i){
        int u;
        cin >> u;
        if (res.empty()){
            res.push_back(u);
        } else {
            int low = 0;
            int high = res.size() - 1;
            int ans = -1;
            while (low <= high){
                int mid = low + ((high - low)>>1);
                if (res[mid] <= u){
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            if (ans == -1){
                res.push_back(u);
            } else {
                res[ans] = u;
            }
        }
    }
    cout << res.size();
    
    return 0;
}
