// 5473. 简单数对推理
// Created by DNX on 2024/2/24.
//
#include <iostream>

using namespace std;

int cnt[10];

int main()
{
    int num;

    for(int i = 0; i < 4; i++){
        cin >> num;
        ++cnt[num];
    }

    for(int i = 1; i < 10; i++)
    {
        if(cnt[i] == 2){
            cout << i << endl;
            break;
        }
    }

    return 0;
}
