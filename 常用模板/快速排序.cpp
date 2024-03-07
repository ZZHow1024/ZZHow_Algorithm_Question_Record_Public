// 模板_快速排序
// Created by DNX on 2024/3/7.
//
#include <iostream>
#include <algorithm>

#define N 100010

using namespace std;

void quickSort(int l, int r);

int n;
int arr[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;

    return 0;
}

void quickSort(int l, int r) {
    if (l >= r)
        return;

    int x = arr[(l + r) >> 1], i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (arr[i] < x);
        do j--; while (arr[j] > x);
        if (i < j)
            swap(arr[i], arr[j]);
    }

    quickSort(l, j);
    quickSort(j + 1, r);
}
