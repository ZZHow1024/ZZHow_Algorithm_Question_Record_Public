// 模板_差分
// AcWing_797. 差分
// Created by DNX on 2024/3/29.
//
#include<iostream>

#define N 100010

using namespace std;

void insert(int l, int r, int c);

int n, m;
int a[N], b[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        insert(i, i, a[i]);

    while (m--) {
        int l, r, c;
        cin >> l >> r >> c;
        insert(l, r, c);
    }

    for (int i = 1; i <= n; i++)
        b[i] += b[i - 1];

    for (int i = 1; i <= n; i++)
        cout << b[i] << ' ';

    cout << endl;

    return 0;
}

void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}
