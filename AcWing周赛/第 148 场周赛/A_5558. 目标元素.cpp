// 5558. 目标元素
// Created by DNX on 2024/3/23.
#include <iostream>

#define N 110

using namespace std;

int n, k;
int arr[N];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << arr[k - 1] << endl;

    return 0;
}
