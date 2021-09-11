#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;

const int MXN  = 1e5+7;

ll square[MXN];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    //precompute the i^2
    for(ll i = 1; i < MXN; ++i){
        square[i] = i*i;
    }

    int ncase; // number of testcase
    cin >>ncase;

    //for every testcase
    while(ncase--){
        ll k;
        cin >> k; // read the number k

        //find the smallest size n of square include K
        ll n = lower_bound(square, square + MXN, k) - square ; 
        //simplize
        k = k - square[n-1];
        //calculate
        if(k > n) cout << n << ' ' << 2*n - k << '\n';
        else{
            cout << k << ' ' << n << '\n';
        }
    }
    return 0;
}