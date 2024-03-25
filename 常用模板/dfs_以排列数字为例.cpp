// 模板_dfs_以排列数字为例
// AcWing_842. 排列数字
// Created by DNX on 2024/3/14.
//
#include <iostream>

#define N 10

using namespace std;

void dfs(int u);

int n;
int path[N];
bool st[N];

int main()
{
    cin >> n;

    dfs(0);

    return 0;
}

void dfs(int u)
{
    if(u == n)
    {
        for(int i = 0; i < n; i++)
            cout << path[i] << ' ';
        cout << endl;
        return;
    }

    for(int i = 1; i <= n; i++)
        if(!st[i])
        {
            path[u] = i;
            st[i] = true;
            dfs(u + 1);
            //恢复现场
            st[i] = false;
        }
}
