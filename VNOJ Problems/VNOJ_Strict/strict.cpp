#include <iostream>
#include <set>
#include <vector>
using namespace std;

#define ll long long

const int N = 2e5+7, R = 1e9+7;
// c[i]: số lần số nhỏ thứ i trong mảng A xuất hiện
//    k: số lượng giá trị khác nhau
// t[i]: tích mọi (j+1) thuộc c[i:k] với nhau
int n, a[N], k; ll c[N], t[N];

void compress() {
	set<int> s(a, a+n);
	vector<int> v(s.begin(), s.end());
	k = v.size();
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		c[ a[i] ]++;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	compress();
	t[k] = 1;
	for (int i = k-1; i >= 0; i--) {
		t[i] = (c[i]+1) * t[i+1] % R;
	}
	//
	ll r = 1;
	for (int i = 0; i < k; i++) {
		r += c[i] * t[i+1]; r %= R;
	}
	cout << r << "\n";
	return 0;
}
