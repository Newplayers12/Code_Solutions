#include <bits/stdc++.h>

using namespace std;

struct point 
{
	long double x, y;
	point() {}
};
#define ld long double

int dx[] = {-1, 1, 1, -1};
int dy[] = {1, 1, -1, -1};

const int MXN = 1e5;
point p[MXN + 2];
int n;
ld f(ld x, ld y){
	ld res = 0;
	for(int i = 0; i < n; ++i){
		ld xx = (x - p[i].x);
		ld yy = (y - p[i].y);
		res += sqrt(xx*xx + yy*yy);
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> p[i].x >> p[i].y;
	}
	ld ex, ey;
	ex = ey = 0;
	ld cur = f(ex, ey);
	ld step = 1e2;
	
	for(int i = 0; i < 1000; ++i){
		int pos = -1;
		for(int k = 0; k < 4; ++k){
			ld nx = ex + step*dx[k];
			ld ny = ey + step*dy[k];
			if (f(nx, ny) < cur){
				pos = k;
			}
		}
		if (pos == -1){
			step /= 2;
			if (fabs(step) < (1e-11)) break;
		} else {
			ex += dx[pos]*step;
			ey += dy[pos]*step;
			cur = f(ex, ey);
		}
	}
	cout << setprecision(11) << fixed << ex << ' ' << ey;
}
