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

#define deb(x) cout << '[' << #x << ']' << ' ' << x << endl

const int MXN = 2e5 + 7;

ll f[MXN];

const ll MOD = 1e9 + 7;

void compress(vll &a)
{
    set<ll> s(a.begin(), a.end());
    vll l(s.begin(), s.end());
    for (auto &x : a)
    {
        x = lower_bound(l.begin(), l.end(), x) - l.begin() + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vll a(n);
    //nhap lieu
    for (auto &c : a)
        cin >> c;

    //vi day la bai toan dem ta co the nen phan tu lai theo gia tri cua chung cho de dang xu ly
    compress(a);

    // sap xep lai mang
    sort(a.begin(), a.end());

    // dem so luong cac phan tu co gia tri giong nhau
    vi cnt(n + 1);
    for (int i = 0; i < n; ++i)
    {
        cnt[a[i]]++;
    }

    // goi f la so cach tao nen day B co tinh nghiem ngat khi gia tri dung cuoi la i
    memset(f, 0, sizeof(f));

    f[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        f[i] = f[i - 1] * (cnt[i] + 1) % MOD;
    }

    cout << f[n];
    return 0;
}
