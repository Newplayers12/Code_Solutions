/*
    author:    Newplayers12
    created:   Thursday 16-09-2021  09:24:05
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<int> a(n);

    for (int &x : a)
        cin >> x;

    int Max = INT_MIN;
    for(int i = 2; i < n; ++i){
        Max = max(Max, a[i] - a[i-2]); // nếu mà mình bỏ đi phần tử thứ i thì mình sẽ xét i và i - 2 có phải là một chệnh lệch lớn nhất mới ko?
    }
    cout << Max;
    return 0;
}