
/*
author:		iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	untracked
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/


/*
thêm vào bên phải 
--> số cặp cộng thêm == số các số lớn hơn p đã có trong deque
thêm vào bên trái
--> số cặp cộng thêm == số các số bé hơn p đã có trong deque
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

#define ll long long

const ll N = 2e5+7, R = 1e9+7;
ll n, a[N], f[N], g[N];

/**
 * fenwick tree
 * */
// lấy ra số các số lớn hơn p
ll fget(ll p) {
	ll r = 0;
	while (p <= n) {
		r += f[p]; r %= R;
		p += p&-p;
	}
	return r;
}

void fupd(ll p) {
	while (p > 0) {
		f[p]++;
		p -= p&-p;
	}
}

// lấy ra các số nhỏ hơn p
ll gget(ll p) {
	ll r = 0;
	while (p > 0) {
		r += g[p]; r %= R;
		p -= p&-p;
	}
	return r;
}

void gupd(ll p) {
	while (p <= n) {
		g[p]++;
		p += p&-p;
	}
}


/**
 * 
 * */
void compress() {
	set<ll> s(a, a+n);
	vector<ll> v(s.begin(), s.end());
	for (ll i = 0; i < n; i++) {
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t; cin >> t;
	while (t--) {
		cin >> n;
		for (ll i = 0; i < n; i++) cin >> a[i];
		//
		ll r = 0;
		compress();
		memset(f, 0, n*sizeof(f[0]) + 1);
		memset(g, 0, n*sizeof(g[0]) + 1);
		for (ll i = 0; i < n; i++) {
			r += min(fget(a[i]+1), gget(a[i]-1));
			fupd(a[i]);
			gupd(a[i]);
		}
		cout << r << "\n";
	}
	return 0;
}
