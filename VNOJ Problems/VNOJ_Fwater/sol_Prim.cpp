/*
	author:    Newplayers12
	created:   Saturday 11-09-2021  10:44:13
*/
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0)
const int MXN = 305;
vector<pii> graph[MXN];
int dist[MXN];
int n;
const int INF = 1e9;

void Prim(int start)
{
	bool flag[MXN];
	memset(flag, false, sizeof(flag));

	for (int i = 0; i <= n; ++i)
	{
		dist[i] = INF;
	}
	dist[start] = 0;

	priority_queue<pii> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		int u = pq.top().second;
		int du = -pq.top().first;
		pq.pop();
		if (du != dist[u])
			continue;
		flag[u] = true;
		for (pii p : graph[u])
		{
			if (!flag[p.second] && dist[p.second] > p.first)
			{
				dist[p.second] = p.first;
				pq.push(make_pair(-dist[p.second], p.second));
			}
		}
	}
	int sum = 0;

	for (int i = 0; i <= n; ++i)
	{
		sum += dist[i];
		// cout << dist[i] << ' ';
	}
	cout << sum;
}

int main()
{
	fastio;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int cost;
		cin >> cost;
		graph[0].push_back(make_pair(cost, i));
		graph[i].push_back(make_pair(cost, 0));
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{

			int cost;
			cin >> cost;
			if (i == j)
				continue;
			graph[i].push_back(make_pair(cost, j));
		}
	}
	Prim(0);
	return 0;
}