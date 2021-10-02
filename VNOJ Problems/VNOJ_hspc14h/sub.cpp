/*
bài toán dễ hơn:
cho mảng A có N số nguyên
-1e3 < Ai < 1e3

với K là điểm chia mảng thành hai phần sao cho 
	tổng giá trị tuyệt đối của số âm trong A[0:K]
      + tổng giá trị tuyệt đối của số dương trong A[K:N] 
là cực đại

tìm giá trị cực đại đó 
*/

#include <iostream>
using namespace std;

const int N = 1e5+7;
// dpn = dp_negative; dpp = dp_positive;
int n, a[N], dpn[N], dpp[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	//
	for (int i = 1; i <= n; i++) {
		dpn[i] = dpn[i-1];
		if (a[i] < 0) dpn[i] += -a[i];
	}
	for (int i = n; i >= 1; i--) {
		dpp[i] = dpp[i+1];
		if (a[i] > 0) dpp[i] += a[i];
	}
	//
	int r = 0;
	for (int i = 1; i <= n; i++) {
		r = max(r, dpn[i] + dpp[i]);
	}
	cout << r << endl;
	return 0;
}
