/*
    author:    Newplayers12
    created:   Wednesday 22-09-2021  14:02:04
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define pii pair<int, int>

int arr[6][6];
vector<pii> pos;

bool flag[6][6];

bool isValid(int x, int y)
{
    return 0 <= x && x <= 5 && 0 <= y && y <= 5;
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool BFS(int area)
{
    queue<pii> q;
    q.push(pos[0]);
    flag[pos[0].first][pos[0].second] = false;
    int spot = 0;
    int vil = 0;
    while (!q.empty())
    {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        for (int i = 0; i < (int)pos.size(); ++i)
        {
            if (pos[i] == make_pair(u, v))
            {
                vil++;
            }
        }
        spot++;
        for (int k = 0; k < 4; ++k)
        {
            int nu = u + dx[k];
            int nv = v + dy[k];
            if (isValid(nu, nv) && flag[nu][nv])
            {
                flag[nu][nv] = false;
                q.push(make_pair(nu, nv));
            }
        }
    }
    return (vil == int(pos.size()) && spot == area);
}

bool BFS_white(int area)
{
    queue<pii> q;
    q.push(make_pair(0, 0));
    flag[0][0] = false;
    int spot = 0;

    while (!q.empty())
    {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        spot++;
        for (int k = 0; k < 4; ++k)
        {
            int nu = u + dx[k];
            int nv = v + dy[k];
            if (isValid(nu, nv) && flag[nu][nv])
            {
                flag[nu][nv] = false;
                q.push(make_pair(nu, nv));
            }
        }
    }
    return spot == area;
}

int main()
{
    fastio;
    pos.clear();
    for (int i = 1; i <= 4; ++i)
    {
        for (int j = 1; j <= 4; ++j)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                pos.push_back(make_pair(i, j));
            }
        }
    }
    int ans = 0;
    for (int num = 0; num < (1 << 16); ++num)
    {
        bitset<16> f(num);
        bool can = true;
        int area = 16;
        memset(flag, true, sizeof(flag));

        for (int i = 0; i <= 5; ++i)
        {
            flag[i][0] = flag[i][5] = flag[0][i] = flag[5][i] = false;
        }
        
        for (int i = 0; i < 16; ++i)
        {
            int row = i / 4;
            row++;
            int col = i % 4;
            col++;

            if (arr[row][col] == 1 && f[i])
            {
                can = false;
                break;
            }

            if (f[i])
            {
                flag[row][col] = false;
                area--;
            }
        }

        if (!can)
            continue;
        if (BFS(area))
        {
            area = 36;
            memset(flag, true, sizeof(flag));

            for (int i = 0; i < 16; ++i)
            {
                int row = i / 4;
                row++;
                int col = i % 4;
                col++;
                if (!f[i])
                {
                    flag[row][col] = false;
                    area--;
                }
            }
            if (BFS_white(area))
            {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}