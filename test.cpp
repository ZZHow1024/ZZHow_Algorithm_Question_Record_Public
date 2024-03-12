// 5_兽之泪(不是最优解)
// Created by DNX on 2024/3/9.
#include <iostream>
#include<algorithm>

#define N 100010
using namespace std;

bool check();

int k, n;
int x[N], y[N];
int z[N];
bool state[N];
int ans;
int tar;
bool all;

int main() {
    cin >> k >> n;
    for (int i = 0; i < k; i++)
        cin >> x[i] >> y[i];

    memcpy(z, x, sizeof z);


    int index, min;
    for (int i = 0; i < k; i++) {
        if (tar == n)
            break;
        if (check())
            break;
        index = (int) (min_element(z, z + k - 1) - z);
        min = *min_element(z, z + k - 1);
        ans += min;
        ++tar;
        if (!state[index]) {
            state[index] = true;
            z[index] = y[index];
        }
    }

    if (tar != n && all) {
        for (int i = 0; i < k; i++) {
            if (tar == n)
                break;
            index = (int) (min_element(z, z + k) - z);
            min = *min_element(z, z + k);
            ans += min;
            ++tar;
            if (!state[index]) {
                state[index] = true;
                z[index] = y[index];
            }
        }
    }

    cout << ans << endl;

    return 0;
}

bool check() {
    for (int i = 0; i < k; i++) {
        if (!state[i])
            return false;
    }

    all = true;
    return true;
}
