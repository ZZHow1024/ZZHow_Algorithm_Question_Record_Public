// 3.奇偶排序
// Created by DNX on 2024/3/9.
//
#include <iostream>
#include <algorithm>

#define N 1010

using namespace std;

int n;
int tmp;
int j[N];
int jj;
int o[N];
int oo;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        if(tmp % 2)
            j[jj++] = tmp;
        else
            o[oo++] = tmp;
    }

    sort(j, j + jj);
    sort(o, o + oo);

    for(int i = 0; i < jj; i++)
        cout << j[i] << ' ';
    for(int i = 0; i < oo; i++)
        cout << o[i] << ' ';
    cout << endl;

    return 0;
}
