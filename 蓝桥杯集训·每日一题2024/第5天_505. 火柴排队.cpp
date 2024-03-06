// 第5天_505. 火柴排队
// Created by DNX on 2024/3/6.
//
#include <iostream>
#include <cstdio>
#include <algorithm>

#define MOD 99999997
#define N 100010

using namespace std;

typedef long long LL;

void work(int a[]);
LL mergeSort(int l, int r);

int n;
int a[N];
int b[N];
int c[N];
int tmp[N];
int p[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);

    //进行离散化
    work(a);
    work(b);
    for (int i = 1; i <= n; i++)
        c[a[i]] = i;
    for (int i = 1; i <= n; i++)
        b[i] = c[b[i]];

    cout << (mergeSort(1, n)) % MOD << endl;

    return 0;
}

void work(int a[]) {
    for (int i = 1; i <= n; i++)
        p[i] = i;

    sort(p + 1, p + 1 + n, [&](int x, int y) {
        return a[x] < a[y];
    });

    for (int i = 1; i <= n; i++)
        a[p[i]] = i;
}

LL mergeSort(int l, int r) {
    if (l >= r)
        return 0;

    int mid = (l + r) >> 1;
    LL res = mergeSort(mid + 1, r) + mergeSort(l, mid);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (b[i] < b[j])
            tmp[k++] = b[i++];
        else {
            tmp[k++] = b[j++];
            res += mid - i + 1;
        }
    }

    while (i <= mid)
        tmp[k++] = b[i++];

    while (j <= r)
        tmp[k++] = b[j++];

    for (i = l, j = 0; i <= r; i++, j++)
        b[i] = tmp[j];

    return res;
}
