// 模板_前缀和
// AcWing_795. 前缀和
// Created by DNX on 2024/3/27.
//
#include <iostream>

#define N 100010

using namespace std;

int n, m;
int a[N], s[N];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];

    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}
