// 2_霓虹(暴力破解)
// Created by DNX on 2024/3/9.
#include <iostream>
#include <cstring>

#define N 100010

using namespace std;

typedef long long LL;

int main()
{
    int ans[10][10] =
            {{0,4,3,3,4,3,2,3,1,2},
             {4,0,5,3,2,5,6,1,5,4},
             {3,5,0,2,5,4,3,4,2,3},
             {3,3,2,0,3,2,3,2,2,1},
             {4,2,5,3,0,3,4,3,3,2},
             {3,5,4,2,3,0,1,4,2,1},
             {2,6,3,3,4,1,0,5,1,2},
             {3,1,4,2,3,4,5,0,4,3},
             {1,5,2,2,3,2,1,4,0,1},
             {2,4,3,1,2,1,2,3,1,0}};

    char str1[N];
    char str2[N];
    int a, b;
    LL res = 0;

    cin >> str1;
    cin >> str2;

    for(int i = 0; i < strlen(str1); i++)
    {
        a = str1[i] - '0';
        b = str2[i] - '0';

        res += (LL)ans[a][b];
    }

    cout << res << endl;

    return 0;
}