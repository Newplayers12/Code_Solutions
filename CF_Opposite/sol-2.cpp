/*
    author:    Newplayers12
    created:   Thursday 16-09-2021  09:35:00
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    fastio;
    int test;
	cin >> test;
	while(test--){
		int a, b, c;
		cin >> a >> b >> c;
		if (a > b) swap(a, b);
		int nb = b - (a - 1); // người đối diện người 1
		int len = 2*(b - a); // số người trong vòng tròn
		int num;
		if (c > len || b > len){
			cout << -1;
			cout << '\n';
			continue;
		}
		if (c < nb){ // người c < người dối diện 1 thì người dối diện c sẽ > người dối diện 1
			num = c + len/2;
		} else { // ngược lại
			num = c - len/2;
		}

		if (num <= len && num != a && num != b){
			cout << num;
		} else cout << -1;
		cout << '\n';
 
	}
    return 0;
}