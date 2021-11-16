/*
    author:    Newplayers12
    created:   Tuesday 16-11-2021  19:54:00
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

struct SegTree
{
    int size;
    vector<int> num[2];

    void init(int n){
        size = 1;
        while (size < n) size <<= 1;
        
        for(int i = 0; i < 2; ++i){
            num[i].assign(2*size, 1e9);
        }
    }

    void setv(int id, vector<int> v, int x, int lx, int rx){
        if (rx - lx == 1){
            for(int i = 0; i < 2; ++i){
                num[i][x] = v[i];
            }
            return ;
        }
        int mid = (lx + rx)/2;

        if (id < mid){
            setv(id, v, 2*x + 1, lx, mid);
        } else {
            setv(id, v, 2*x + 2, mid, rx);
        }
        
        for(int i = 0; i < 2; ++i)
            num[i][x] = min(num[i][2*x + 1], num[i][2*x + 2]);
        return;
    }

    int getRange(int l, int r, int type, int x, int lx, int rx){
        if (r <= lx || rx <= l) return 1e9;
        if (l <= lx && rx <= r) return num[type][x];
        int mid = (lx + rx)/2;

        int left = getRange(l, r, type, 2*x + 1, lx, mid);
        int right = getRange(l, r, type, 2*x + 2, mid, rx);
        return min(left, right);
    }
    int getv(int k){
        return  min(getRange(0, k, 0, 0, 0, size) + k
                    ,getRange(k ,size, 1, 0, 0, size) - k); 
    }
};


int main()
{
    fastio;
    SegTree st;
    int n, q;
    cin >> n >> q;
    st.init(n);
    for(int i = 0; i < n; ++i){
        int u;
        cin >> u;
       
        st.setv(i, (vector<int>){u - i, u + i}, 0, 0, st.size);
    }
    
    while(q --){
        int t;
        cin >> t;
        if (t == 1) {
            int k, x;
            cin >> k >> x;
            k--;
            st.setv(k, (vector<int>){x - k, x + k}, 0, 0, st.size);
        } else {
            int k;
            cin >> k;
            k--;
            cout << st.getv(k) << '\n';
        }
    }
    return 0;
}