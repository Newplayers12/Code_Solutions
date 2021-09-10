#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

const int mxn = 350;

int c[mxn][mxn];


struct edge{
	int u,v,w;
	edge(int _u,int _v,int _w){
		u = _u;v = _v;w  = _w;
	}
	bool operator < (edge& other){
		return w < other.w;
	}
};

struct UnionFind {
	vi par,rank;
	UnionFind(int N){ // cai nay la Contructor cua Class trong C++. Co the thay bang ham "void init(){...}"
		rank.assign(N, 0);
		par.resize(N);
		for(int i =0; i < N; ++i){
			par[i] = i;
		}
	}

	int findSet(int u){ 
		if(u == par[u]) return u;
		return par[u] = findSet(par[u]); // cho nay la path compression
	}

	bool isSameSet(int u, int v){
		return findSet(u)==findSet(v);
	}

	void UnionSet(int u, int v){
		u = findSet(u);
		v = findSet(v);
		if(u!=v){                  // cai nay dung de check 2 tap hop co giao nhau hay la khong
			if(rank[u] < rank[v]){ // luon compress vo cay co rank lon hon
				int tmp = u;
				u = v;
				v = tmp;
			}
			par[v] =u;
			if(rank[u] ==rank[v]) rank[u]++;
		}
	}
};


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin >> n ;

    // nhap canh cua do thi
	vector<edge> edges;
	for(int i = 1; i<= n;++i){
		int x;
		cin >> x;
		edges.push_back(edge(0,i,x));
		edges.push_back(edge(i,0,x));
	}

	for(int i =1;i<=n;++i){
		for(int j=1; j<=n;++j){
			int x;
			cin >>x ;
			if(i != j) edges.push_back(edge(i,j,x));
		}
	}


    //xay dung cay khung nho nhat
	sort(edges.begin(),edges.end());

	UnionFind dsu(n+1);
	long long ans = 0;
	for(auto&e : edges){
		int u = e.u;
		int v = e.v;
		int w = e.w;
		if(!dsu.isSameSet(u,v)){
			ans +=w;
			dsu.UnionSet(u,v);
		}
	}

	cout << ans;
	return 0;
}
