// 第4天_3745. 牛的学术圈 I(双指针算法)
// Created by DNX on 2024/3/5.
//
#include <iostream>
#include <cstdio>
#include <algorithm>

#define N 100010

using namespace std;

int n, l;
int w[N];

int main()
{
    cin >> n >> l;
    for(int i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    sort(w+1, w + n + 1, greater<int>());

    int res = 0;
    for(int i = 1, j = n; i <= n; i++)
    {
        while(j && w[j] < i)
            j--;
        if(w[i] >= i-1 && i - j <= l)
            res = i;
    }

    cout << res << endl;

    return 0;
}
