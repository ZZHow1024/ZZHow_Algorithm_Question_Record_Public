// 5555. 平衡数组
// Created by DNX on 2024/3/16.
#include <iostream>

using namespace std;

int n;
int tmp;
int j, o;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        if(tmp % 2)
            ++j;
        else
            ++o;
    }

    if(j == o)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
