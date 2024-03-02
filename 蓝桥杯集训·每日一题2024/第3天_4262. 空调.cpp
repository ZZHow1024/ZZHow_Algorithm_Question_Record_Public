// 第3天_4262. 空调
// Created by DNX on 2024/3/2.
//
#include <iostream>
#include <cstdio>

#define N 100010

using namespace std;

int n;
int p[N];
int t[N];
int pt[N];
int sub[N];
int a, b;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &t[i]);

    for (int i = 1; i <= n; i++) {
        pt[i] = p[i] - t[i];
        sub[i] = pt[i] - pt[i-1];
    }

    for(int i = 1; i <= n; i++)
        if(sub[i] > 0)
            a += sub[i];
        else if(sub[i] < 0)
            b -= sub[i];

    cout << max(a,b) << endl;

    return 0;
}
