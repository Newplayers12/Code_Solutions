/*
    author:    Newplayers12
    created:   Sunday 26-09-2021  14:31:58
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int MXN = 1e4 + 5;

vector<pair<int, int>> graph[MXN]; // vector< vector<pair<int, int>> >
// Danh sách kề - Prim
// Ma trận kề
// danh sách cạnh - Kruskal

int cha[MXN]; // cha[i] là đỉnh đại diện cho thằng i

int find(int x){ 
    if (x != cha[x]){
        cha[x] = find(cha[x]); // nén đường
    }
    return cha[x];
}


struct Edge {
    int first, second;
    int cost;
    /*
    bool operator < (const Edge& other){
        return cost < other.cost;
    }
    // ed[1] < ed[2]
    */
};

int n, m;
const int INF = 1e9;

// Prim
// void Prim(int start){
//     vector<int> dist(n, INF);
//     priority_queue< pair<int, int> > pq; // mặc định của priority_queue là max lên đầu?
//     // 12
//     // 23
//     // 20

//     // -12
//     // -23
//     // -20
//     pq.push(make_pair(0, start));
//     // <first, second> first == nhau thì mới so sanh second.
//     dist[start] = 0;

//     vector<bool> flag(n, false);
//     flag[start] = true;
    
//     while(!pq.empty()){
//         int u = pq.top().second;
//         int du = -pq.top().first;
//         pq.pop();

//         if (du != dist[u]){
//             continue;
//         }
//         flag[u] = true;
        
//         for(pair<int, int> p: graph[u]){
//             int v = p.first;
//             int w = p.second;
//             if (flag[v] == false && dist[v] > w){
//                 dist[v] = w;
//                 pq.push(make_pair(-dist[v], v));
//             }
//         } 
//     }
//     int sum = 0;
//     for(int i = 0; i < n; ++i){
//         //cout << dist[i] << ' ';
//         sum += dist[i];
//     }
//     cout << sum << '\n';


// }


bool cmp(const Edge& a, const Edge& b){ 
    return a.cost < b.cost;
}

// int mod = 23 // chậm hơn
// const int mod = 23; // nhanh hơn
// 34 - 23 % mod 

int main()
{
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cha[i] = i;
    }
    vector<Edge> ed(m);
    for(int i = 0; i < m; ++i){
        cin >> ed[i].first >> ed[i].second >> ed[i].cost;
        ed[i].first --;
        ed[i].second --;
    }    
    //Prim(0);
    sort(ed.begin(), ed.end(), cmp);
    int sum = 0;
    for(auto x:ed){
        int pA = find(x.first);
        int pB = find(x.second);
        if (pA == pB) {
            continue;
        }
        if (rand() & 1){ // rand() là số lẻ thì swap // rand() = x = 101010101 & 1 là một hàm lấy số nguyên random, 2 = 10, 4 = 100, 5 = 101
            swap(pA, pB);
        }
        cha[pA] = pB;
        sum += x.cost;
    }
    cout << sum << '\n';
    return 0;
}