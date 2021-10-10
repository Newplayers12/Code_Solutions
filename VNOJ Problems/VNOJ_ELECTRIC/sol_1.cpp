#include <bits/stdc++.h>
using namespace std;

void deb(int x){ cout << x << "\n";}
const int INF = 1e9;

vector<pair<int, int>> adjacent[4005];
vector<pair<int, int>> new_adjacent[4005];
int dis[4005];
long long res;
int w[4005][4005];
void bfs(int s){
    int *distance = w[s];
    queue<int> qu;
    vector<bool> flag(4005, false);
    qu.push(s);
    flag[s] = true;
    distance[s] = 0;
    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        for(auto item : new_adjacent[u]){
            int v = item.first;
            int dv = item.second;
            if(flag[v] == true) continue;
            distance[v] = max(distance[u], dv);
            qu.push(v);
            flag[v] = true;
        }
    }
}
void prim_first(int s){
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    memset(dis, 0x73737373, sizeof dis);
    dis[s] = 0;
    pq.push(make_pair(0, make_pair(s, s)));
    while(!pq.empty()){
        int u = pq.top().second.first;
        int k = pq.top().second.second;
        int du = pq.top().first;
        pq.pop();
        if(dis[u] != du) continue;
        new_adjacent[u].push_back(make_pair(k, du));
        new_adjacent[k].push_back(make_pair(u, du));
        res += dis[u];
        dis[u] = -INF;
        for(pair<int, int> item : adjacent[u]){
            int v = item.first;
            int dv = item.second;
            if(dis[v] > dv){
                dis[v] = dv;
                pq.push(make_pair(dv, make_pair(v, u)));
            }
        }
    }
}
void solve(){
    int u1, u2;
    cin >> u1 >> u2;
    int weight;
    if(w[u1][u2] == 0 && w[u2][u1] == 0){
        bfs(u1);
    }
    weight = max(w[u1][u2], w[u2][u1]);
    cout << res - weight << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        adjacent[u].push_back(make_pair(v, w));
        adjacent[v].push_back(make_pair(u, w));
    }
    prim_first(1);
    int q;
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
}