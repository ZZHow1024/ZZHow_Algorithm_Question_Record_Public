// 第4天_3745. 牛的学术圈 I(二分算法)
// Created by DNX on 2024/3/5.
//
#include <iostream>
#include <cstdio>
#include <algorithm>

#define N 100010

using namespace std;

bool check(int mid);

int n, l;
int w[N];

int main() {
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    int ll = 0;
    int rr = n;
    while (ll < rr) {
        int mid = (ll + rr + 1) >> 1;
        if (check(mid))
            ll = mid;
        else
            rr = mid - 1;
    }

    cout << ll << endl;

    return 0;
}

bool check(int mid) {
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        if (w[i] >= mid)
            ++a;
        else if (w[i] == mid - 1)
            ++b;
    }

    return a + min(b, l) >= mid;
}
