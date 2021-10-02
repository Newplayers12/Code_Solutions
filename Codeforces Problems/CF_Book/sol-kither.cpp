#include <bits/stdc++.h>
using namespace std;
 
bool isCycle(int u, vector<bool> &visited, vector<bool> &res_stack,  vector<int>  adjacent[]){
    if(!visited[u]){
        visited[u] = true;
        res_stack[u] = true;
        for(int v : adjacent[u]){
            if(!visited[v] && isCycle(v, visited, res_stack, adjacent)){
                return true;
            }
            else if(res_stack[v]) return true;
        }
    }
    res_stack[u] = false;
    return false;
}
vector<int> getWay(int s, vector<int>  adjacent[], vector<int> counted, int n){
    queue<int> qu;
    qu.push(s);
    vector<int> num(n + 1, 0);
    vector<int> local_counted(n + 1, 0);
    num[s] = 0;
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for (int v : adjacent[u]) {
            if(u == 0 || u > v){
                num[v] = max(num[u] + 1, num[v]);
                local_counted[v] += 1;
            }
            else{
                num[v] = max(num[u], num[v]);
                local_counted[v] += 1;
            }
            if(local_counted[v] == counted[v]){
                qu.push(v);
            }
        }
    }
    return num;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vector<int> top;
        vector<int> adjacent[n + 1];
        vector<int> count_res(n + 1);
        for(int i = 1; i <= n; ++i){
            int k;
            cin >> k;
            if(k == 0){
                top.push_back(i);
                count_res[i] = 1;
                continue;
            }
            count_res[i] = k;
            while(k--){
                int chap;
                cin >> chap;
                adjacent[chap].push_back(i);
            }
        }
        if(top.empty()){
            cout << -1 << "\n";
            continue;
        }
        for(int item : top){
            adjacent[0].push_back(item);
        }
        vector<bool> visited(n + 1, false);
        vector<bool> res_stack(n + 1, false);
        if(isCycle(0, visited, res_stack, adjacent)){
            cout << -1 << "\n";
            continue;
        }
        bool divied = false;
        for(int i = 1; i <= n; ++i){
            if(!visited[i]){
                divied = true;
                break;
            }
        }
        if(divied){
             cout << -1 << "\n";
            continue;
        }
        vector<int> num = getWay(0, adjacent, count_res, n);
        int ans = -1e9;
        for(int i = 1; i <= n; ++i){
            ans = max(num[i], ans);
        }
        cout << ans << "\n";
    }
    return 0;
}