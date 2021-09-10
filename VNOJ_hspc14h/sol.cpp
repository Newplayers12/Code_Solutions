#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// see subproblem for more information 
const int N = 1507;
int m, n, mat[N][N], dpn[N][N], dpp[N][N];

void gendp() {
	// basically the whole subproblem
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= m; i++) {
			dpn[i][j] = dpn[i-1][j];
			if (mat[i][j] < 0) dpn[i][j] += -mat[i][j];
		}
	}
	for (int j = 1; j <= n; j++) {
		for (int i = m; i >= 1; i--) {
			dpp[i][j] = dpp[i+1][j];
			if (mat[i][j] > 0) dpp[i][j] += mat[i][j];
		}
	}
}

/**
 * drivers
 * */
void printmat() {
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cout << mat[i][j] << " ";
		} cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			string cell; cin >> cell;
			int v = stoi(cell.substr(1, cell.length() - 1));
			//
			if (cell.at(0) == 'A') {
				mat[i][j] = v;
			} else {
				mat[i][j] = -v;
			}
		}
	}
	//
	gendp();
	for (int i = 1; i <= m; i++) {
		mat[i][1] = dpp[i+1][1];
	}
	//
	for (int i = 1; i <= m; i++) {
		//
		for (int j = 2; j <= n; j++) {
			int pre[3] = {
				mat[i][j-1] + dpn[i-1][j] + dpp[i+1][j],	// left -> right
				mat[i-1][j] - dpp[i][j] + dpp[i+1][j],		// top -> down	!FIX
				mat[i-1][j-1] + dpn[i-1][j] + dpp[i+1][j]	// tl -> dr
			};
			mat[i][j] = *max_element(pre, pre+3);
		}
	}
	cout << mat[m][n] << endl;
	// printmat();
	return 0;
}
