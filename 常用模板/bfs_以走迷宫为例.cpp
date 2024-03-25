// 模板_bfs_以走迷宫为例
// AcWing_844. 走迷宫
// Created by DNX on 2024/3/21.
//
#include <iostream>
#include <cstring>
#include <algorithm>

#define N 110

using namespace std;

int bfs();

typedef pair<int, int> PII;

int n, m;
int g[N][N];
int d[N][N];
PII q[N*N];

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j];

    cout << bfs() << endl;

    return 0;
}

int bfs()
{
    int hh = 0, tt = 0;
    q[0] = {0, 0};

    memset(d, -1, sizeof d);
    d[0][0] = 0;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    while(hh <= tt)
    {
        auto t = q[hh++];

        for(int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;
                q[++tt] = {x, y};
            }
        }
    }

    return d[n-1][m-1];
}
