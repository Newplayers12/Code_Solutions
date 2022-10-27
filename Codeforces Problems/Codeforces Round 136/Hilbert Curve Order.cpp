/*
	author:    Newplayers12
	created:   Thursday 27-10-2022  11:17:05
	Codeforces links for documents: https://codeforces.com/blog/entry/61203
	Codeforces problem link: https://codeforces.com/problemset/problem/221/D
*/
#include <bits/stdc++.h>
using namespace std;

#define all(X) X.begin(), X.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

map<int, int> mp;

inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

struct node
{
	int first, second, id;
	int64_t ord;
	node() {}
	inline void Ord(){
		ord = gilbertOrder(first, second, 21, 0);
	}
};





void add(int x, int& ans){
	int prev = mp[x]++;

	if (prev == x) --ans;
	if (prev == x - 1) ++ans;
}

void remove(int x, int& ans){
	int prev = mp[x]--;
	if (prev == x) --ans;
	if (prev == x + 1) ++ans;
}

int S, n, q;

int main()
{
	fastio;
	cin >> n >> q;
	vector<int> a(n);
	for(int &x:a) cin >> x;
	vector<node> query(q);
	S = sqrt(n + .0) + 1;
	for(int i = 0; i < q; ++i){
		cin >> query[i].first >> query[i].second;
		query[i].first--;
		query[i].second--;
		query[i].id = i;
		query[i].Ord();
	}

	sort(begin(query), end(query), [&](node a, node b){
			return a.ord < b.ord;
		});
	int cur_l, cur_r;
	cur_l = 0;
	cur_r = -1;
	int ans = 0;
	vector<int> res(q);

	for(int i = 0; i < q; ++i){
		while (cur_l > query[i].first){
			--cur_l;
			add(a[cur_l], ans);
		}

		while (cur_r < query[i].second){
			++cur_r;
			add(a[cur_r],ans);
		}

		while (cur_l < query[i].first){
			remove(a[cur_l], ans);
			++cur_l;
		}

		while (cur_r > query[i].second){
			remove(a[cur_r], ans);
			--cur_r;
		}

		res[query[i].id] = ans;

	}
	for(int x:res) cout << x << '\n';
	return 0;
}
