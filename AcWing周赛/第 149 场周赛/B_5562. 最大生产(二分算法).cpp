// B_5562. 最大生产(二分算法)
// Created by DNX on 2024/3/30.
#include <iostream>

#define N 100010

using namespace std;
typedef long long LL;

bool check(int mid);

int n, m;
int a[N], b[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    LL l = 0;
    LL r = 2e9;
    while (l < r) {
        int mid = (int)((l + r + 1) >> 1);
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }

    cout << l << endl;

    return 0;
}

bool check(int mid) {
    LL res = 0;
    for (int i = 0; i < n; i++) {
        LL need = (LL) mid * a[i];
        if (need > b[i]) {
            res += need - b[i];
            if (res > m)
                return false;
        }
    }

    return true;
}
