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

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int ncase;
    cin >> ncase;
    while(ncase--){
        ll s,n;
        cin >> s >> n;
        vi a(n, 0);
        int pos = 0;
        for(int base = 1000000000; base >= 1; base /=10){
            while(s >= base && (s - base) >= (n - pos - 1)) // dieu kien thu 2 la de cong cho het phan du phan con lai cho du n so
            {
                a[pos] += base;
                s -= base;
                ++pos;
                if(pos == n){
                    pos = n-1;
                }
            }
        }

        for(auto& c : a) cout << c << ' ';
        cout << '\n';
    }
    return 0;
}
