// 第6天_1262. 鱼塘钓鱼
// Created by DNX on 2024/3/9.
//
#include <iostream>
#include <cstring>
#include <algorithm>

#define N 110

using namespace std;

int solve(int n, int t);
int get(int k);

int a[N], d[N], l[N], spend[N];

int main()
{
    int n, t;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> d[i];
    for(int i = 2; i <= n; i++)
    {
        cin >> l[i];
        l[i] += l[i - 1];
    }

    cin >> t;

    int res = 0;
    for(int i = 1; i <= n; i++)
        res = max(res, solve(i, t - l[i]));

    cout << res << endl;

    return 0;
}

int solve(int n, int t)
{
    int res = 0;
    memset(spend, 0, sizeof spend);

    for(int i = 0; i < t; i++)
    {
        int tt = 1;
        for(int j = 2; j <= n; j++)
            if(get(tt) < get((j)))
                tt = j;

        res += get(tt);
        ++spend[tt];
    }

    return res;
}

int get(int k)
{
    return max(0, a[k] - d[k] * spend[k]);
}
