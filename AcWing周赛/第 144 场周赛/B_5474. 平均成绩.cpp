// 5474. 平均成绩
// Created by DNX on 2024/2/24.
//
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void solve();

int n;
int score[110];
int cnt;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> score[i];
    }

    sort(score, score + n);

    solve();

    return 0;
}

void solve() {
    int ave;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += score[i];
    }
    ave = (int) round((double) sum / (double) n);

    if (ave == 5) {
        cout << cnt << endl;
        return;
    } else {
        score[cnt++] = 5;
        solve();
    }
}
