// 模板_模拟栈
// 828. 模拟栈
// Created by DNX on 2024/4/1.
//
/*
push x – 向栈顶插入一个数 x；
pop – 从栈顶弹出一个数；
empty – 判断栈是否为空；
query – 查询栈顶元素。
 */
#include <iostream>

#define N 100010

using namespace std;

int m;
int stk[N];
int tt;

int main()
{
    cin >> m;
    while(m--)
    {
        string op;
        int x;

        cin >> op;
        if(op == "push")
        {
            cin >> x;
            stk[++tt] = x;
        }
        else if(op == "pop")
            --tt;
        else if(op == "empty")
            cout << (tt ? "NO" : "YES") << endl;
        else
            cout << stk[tt] << endl;
    }

    return 0;
}
