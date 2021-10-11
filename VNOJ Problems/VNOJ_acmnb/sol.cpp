
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	untracked
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <algorithm>
#include <iostream>
using namespace std;

//@ vars
const int nlim = 8e5 + 1;
int n, nhalf;
//
pair<int, int> arr[nlim];
int res = 0, achose = 0, bchose = 0;


//@ tools
void choose_a(int i) {
	achose++;
	res += arr[i].first;
}

void choose_b(int i) {
	bchose++;
	res += arr[i].second;
}

//@ drivers
int main() {
	// inp
	cin >> n;
	nhalf = n; n <<= 1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	// ưu tiên những cái nhiều chênh lệch
	sort(arr, arr + n, [](pair<int, int> i, pair<int, int> j){
		return abs(i.first - i.second) > abs(j.first - j.second);
	});
	//
	for (int i = 0; i < n; i++) {
		// trường hợp phải ép
		if (achose == nhalf) {
			choose_b(i);
			continue;
		}
		if (bchose == nhalf) {
			choose_a(i);
			continue;
		}

		// 
		// bằng nhau luôn được xếp ở cuối
		if (arr[i].first < arr[i].second) {
			choose_a(i);
		} else {
			choose_b(i);
		}
	}
	cout << res << endl;
	//
	system("pause");
	return 0;
}

