// 第1天_503. 借教室(差分需要教室的数量)
// Created by DNX on 2024/2/29.
//
#include <iostream>
#include <cstdio>
#include <cstring>

#define N 1000010

using namespace std;

typedef long long LL;

bool check(int mid);

int n, m;
int w[N];
int d[N], s[N], t[N];
LL b[N];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &d[i], &s[i], &t[i]);
    }

    int l = 0;
    int r = m;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    //二分到最后一个行的

    if (r == m)
        cout << 0 << endl;
    else
        cout << -1 << endl << l + 1 << endl;
    //最后一个不行的是l 或 r 所以结果需要再加1.

    return 0;
}

bool check(int mid) {
    //这里差分数组求前缀和就是每天需要教室的个数
    memset(b, 0, sizeof b);
    for (int i = 1; i <= mid; i++) {
        b[s[i]] += d[i];
        b[t[i] + 1] -= d[i];
    }

    LL sn = 0;
    for (int i = 1; i <= n; i++) {
        //差分数组的前缀和即sn，就是第i天需要的教室数量
        sn += b[i];
        //当需要的教室数量大于当前的教室的数量表示不行
        if (sn > w[i])
            return false;
    }

    return true;
}
