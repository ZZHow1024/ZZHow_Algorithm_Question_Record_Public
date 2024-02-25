// 等腰三角形【算法赛】暴力过60%
// Created by DNX on 2024/2/24.
//
#include <iostream>
#include <algorithm>

#define N 200010

using namespace std;

void solve();

int n;
int red[N];
int blue[N];
int cnt;
int blueUsed[N];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> red[i];
    }
    sort(red, red + n);
    for (int i = 0; i < n; i++) {
        cin >> blue[i];
    }
    sort(blue, blue + n);

    solve();

    return 0;
}

void solve() {
    int a, b, c;

    for (int i = 0; i < n; i++) {
        a = red[i];
        b = a;

        for (int j = 0; j < n; j++) {
            if(blueUsed[j] == 1)
                continue;
            c = blue[j];
            if (a + b > c && a + c > b && b + c > a){
                ++cnt;
                blueUsed[j] = 1;
                break;
            }
        }
    }

    cout << cnt << endl;
}
