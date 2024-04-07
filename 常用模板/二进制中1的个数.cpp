// 模板_二进制中1的个数
// 801. 二进制中1的个数
// Created by DNX on 2024/4/7.
//
#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;
    while (n--) {
        int x, s = 0;
        cin >> x;

        for (int i = x; i; i -= i & -i)
            s++;

        cout << s << ' ';
    }

    return 0;
}
