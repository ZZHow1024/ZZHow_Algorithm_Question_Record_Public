// A_5561. 棋子数量
// Created by DNX on 2024/3/30.
//
#include <iostream>

#define N 110

using namespace std;

int n;
int tmp;
int ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp)
            ++ans;
    }

    cout << ans << endl;

    return 0;
}
