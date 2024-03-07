// 模板_归并排序
// Created by DNX on 2024/3/7.
//
#include <iostream>

#define N 100010

using namespace std;

void mergeSort(int l, int r);

int n;
int arr[N];
int tmp[N];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(0, n-1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;

    return 0;
}

void mergeSort(int l, int r)
{
    if(l >= r)
        return;

    int mid = (l + r) >> 1;
    mergeSort(l, mid);
    mergeSort(mid+1, r);

    int k = 0, i = l, j = mid+1;
    while(i <= mid && j <= r)
        if(arr[i] <= arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];

    while(i <= mid)
        tmp[k++] = arr[i++];
    while(j <= r)
        tmp[k++] = arr[j++];

    for(i = l, j = 0; i <= r; i++, j++)
        arr[i] = tmp[j];
}
