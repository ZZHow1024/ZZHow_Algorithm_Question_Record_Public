// 第7天_4261. 孤独的照片
// Created by DNX on 2024/3/12.
//
#include <iostream>
#include <algorithm>

#define N 500010

using namespace std;

typedef long long LL;

int n;
char str[N];
int l[N], r[N];

int main()
{
    cin >> n;
    cin >> str;

    for(int i = 0, sh = 0, sg = 0; i < n; i++)
        if(str[i] == 'G')
            l[i] = sh, ++sg, sh = 0;
        else
            l[i] = sg, ++ sh, sg = 0;

    for(int i = n-1, sh = 0, sg = 0; i >= 0; i--)
        if(str[i] == 'G')
            r[i] = sh, ++sg, sh = 0;
        else
            r[i] = sg, ++sh, sg = 0;

    LL res = 0;
    for(int i = 0; i < n; i++)
        res += (LL)l[i] * r[i] + max(l[i] - 1, 0) + max(0, r[i] - 1);

    cout << res << endl;

    return 0;
}
