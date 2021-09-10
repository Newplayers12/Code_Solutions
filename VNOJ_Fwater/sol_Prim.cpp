/*
    author:    Newplayers12
    created:   Friday 10-09-2021  22:18:22
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int MXN = 305;
int n, m;
vector<pair<int, int>> graph[MXN];
int main()
{
    fastio;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int cost;
        cin >> cost;
        graph[0].push_back(make_pair(cost, i));
        graph[i].push_back(make_pair(cost, 0));
    }
    return 0;
}
