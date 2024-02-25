// 数学奇才【算法赛】
// Created by DNX on 2024/2/24.
//
#include <iostream>

typedef long long LL;

using namespace std;

int n;
LL res ;

int main()
{
    LL num;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;

        if(num < 0)
            res += num * (-1);
        else
            res += num;
    }

    cout << res << endl;

    return 0;
}
