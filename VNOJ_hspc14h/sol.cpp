#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int N = 1507;
int m, n, f[N][N], gb[N][N], ga[N][N];

void gendp() {
	// build ga[][] and gb[][]
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= m; i++) {
			gb[i][j] = gb[i-1][j];
			if (f[i][j] < 0) gb[i][j] += -f[i][j];
		}
	}
	for (int j = 1; j <= n; j++) {
		for (int i = m; i >= 1; i--) {
			ga[i][j] = ga[i+1][j];
			if (f[i][j] > 0) ga[i][j] += f[i][j];
		}
	}
}

/**
 * drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			string cell; cin >> cell;
			int v = stoi(cell.substr(1, cell.length() - 1));
			//
			if (cell.at(0) == 'A') {
				f[i][j] = v;
			} else {
				f[i][j] = -v;
			}
		}
	}
	//
	gendp();
	for (int i = 1; i <= m; i++) {
		// i = 1 is kinda the edge case
		f[i][1] = ga[i+1][1];
	}
	//
	for (int i = 1; i <= m; i++) {
		//
		for (int j = 2; j <= n; j++) {
			int pre[3] = {
				f[i][j-1] + gb[i-1][j] + ga[i+1][j],	// left -> right
				f[i-1][j] - ga[i][j] + ga[i+1][j],		// top -> down	!FIX
				f[i-1][j-1] + gb[i-1][j] + ga[i+1][j]	// tl -> dr
			};
			f[i][j] = *max_element(pre, pre+3);
		}
	}
	cout << f[m][n] << endl;
	return 0;
}
