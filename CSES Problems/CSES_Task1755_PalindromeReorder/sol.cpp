/*
    author:    Newplayers12
    created:   Sunday 03-10-2021  18:33:41
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)

int main()
{
    fastio;
    string s;
    cin >> s;
    vector<int> dem(26, 0);
    for (char c : s)
    {
        int id = c - 'A';
        dem[id]++;
    }
    int od = 0;
    int head;
    for (int i = 0; i < 26; ++i)
        if (dem[i] & 1)
        {
            od++;
            head = i;
        }
    if (od > 1)
        cout << "NO SOLUTION";
    else
    {
        for (int i = 0; i < 26; ++i)
        {
            char t = (char)i + 'A';
            for (int j = 0; j < (dem[i] / 2); ++j)
                cout << t;
            dem[i] >>= 1;
        }
        if (od)
            cout << char(head + 'A');
        for (int i = 25; i >= 0; --i)
        {
            char t = (char)i + 'A';
            for (int j = 0; j < dem[i]; ++j)
                cout << t;
        }
    }
    return 0;
}