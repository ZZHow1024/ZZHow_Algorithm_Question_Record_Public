// 模板_二分查找
// Created by DNX on 2024/3/8.
//
#include <iostream>

#define N 100010

using namespace std;

int n, m;
int arr[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    while (m--) {
        int k;
        cin >> k;

        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (arr[mid] >= k)
                r = mid;
            else
                l = mid + 1;
        }

        if (arr[l] != k)
            cout << "-1 -1" << endl;
        else {
            cout << l << ' ';
            l = 0, r = n - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (arr[mid] <= k)
                    l = mid;
                else
                    r = mid - 1;
            }

            cout << l << endl;
        }
    }

    return 0;
}
