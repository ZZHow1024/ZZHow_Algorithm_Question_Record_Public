// 猜灯谜【算法赛】
// Created by DNX on 2024/2/24.
//
#include <iostream>

#define N 100010

using namespace std;

void solve();

int n;
int lantern[N
];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> lantern[i];
    }

    solve();

    return 0;
}

void solve() {
    int res;

    for (int i = 0; i < n; i++) {
        res = 0;

        if (i == 0) {
            res += lantern[n - 1] + lantern[1];
        } else if (i == n - 1) {
            res += lantern[n - 2] + lantern[0];
        } else {
            res += lantern[i - 1] + lantern[i + 1];
        }

        cout << res << ' ';
    }
}
