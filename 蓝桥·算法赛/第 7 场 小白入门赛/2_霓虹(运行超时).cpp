// 2_霓虹(运行超时)
// Created by DNX on 2024/3/9.
//
#include <iostream>
#include <cstring>

#define N 100010

using namespace std;

typedef long long LL;

LL solve(int a, int b);
void change(int a);

int state[7];
int stateA[7];
int stateB[7];

int main()
{
    LL ans = 0;
    int a, b;
    char str1[N];
    char str2[N];

    cin >> str1;
    cin >> str2;

    for(int i = 0; i < strlen(str1); i++)
    {
        a = str1[i] - '0';
        b = str2[i] - '0';

        ans += solve(a, b);
    }

    cout << ans << endl;

    return 0;
}

LL solve(int a, int b) {
    memset(stateA, 0, sizeof stateA);
    memset(stateB, 0, sizeof stateB);
    change(a);
    memcpy(stateA, state, sizeof stateA);
    change(b);
    memcpy(stateB, state, sizeof stateB);

    LL res = 0;

    for(int i = 0; i < 7; i++)
        if(stateA[i] != stateB[i])
            ++res;

    return res;
}

void change(int a)
{
    memset(state, 0, sizeof state);
    switch (a) {
        case 0:
            state[1] = state[2] = state[3] = state[4] = state[5] = state[6] = 1;
            break;
        case 1:
            state[2] = state[3] = 1;
            break;
        case 2:
            state[1] = state[2] = state[4] = state[5] = state[0] = 1;
            break;
        case 3:
            state[1] = state[2] = state[3] = state[4] = state[0] = 1;
            break;
        case 4:
            state[2] = state[3] = state[6] = state[0] = 1;
            break;
        case 5:
            state[1] = state[3] = state[4] = state[6] = state[0] = 1;
            break;
        case 6:
            state[1] = state[3] = state[4] = state[5] = state[6] = state[0] = 1;
            break;
        case 7:
            state[1] = state[2] = state[3] = 1;
            break;
        case 8:
            memset(state, 1, sizeof state);
            break;
        case 9:
            memset(state, 1, sizeof state);
            state[5] = 0;
            break;
    }
}
