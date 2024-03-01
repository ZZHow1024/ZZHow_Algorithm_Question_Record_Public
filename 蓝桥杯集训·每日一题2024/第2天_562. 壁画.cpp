// 第2天_562. 壁画
// Created by DNX on 2024/2/29.
//
#include <iostream>
#include <cstdio>
#include <algorithm>

#define N 5000010

using namespace std;

void getCourse();

void solve();

int t, n;
char str[N];
int course[N];
int sn[N];
int res;

int main() {
    cin >> t;
    getchar();

    for(int i = 1; i <= t; i++) {
//        memset(str,0,sizeof str);
//        memset(course,0,sizeof course);
//        memset(sn,0,sizeof sn);
        getCourse();

        solve();

        printf("Case #%d: %d\n", i, res);
    }

    return 0;
}

void getCourse() {
    cin >> n;
    getchar();

    scanf("%s", str);
    getchar();
    for (int i = 1; i <= n; i++)
        course[i] = str[i - 1] - '0';
}

void solve() {
    res = 0;
    int cnt;
    if (n % 2) {
        cnt = n / 2 + 1;
    } else {
        cnt = n / 2;
    }
    for (int i = 1; i <= n; i++)
        sn[i] = sn[i - 1] + course[i];

    for (int i = cnt; i <= n; i++)
        res = max(res, sn[i] - sn[i - cnt]);
}
