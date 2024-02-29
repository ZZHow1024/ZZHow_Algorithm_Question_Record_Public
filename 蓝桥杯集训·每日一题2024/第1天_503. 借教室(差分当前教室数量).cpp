// 第1天_503. 借教室(差分当前教室数量)
// Created by DNX on 2024/2/29.
//
#include <iostream>
#include <cstdio>

#define N 1000010

using namespace std;
typedef long long LL;
int n, m;
int w[N];
int d[N], s[N], t[N];
LL b[N];

bool check(int mid);

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        scanf("%d",&w[i]);
    for(int i = 1; i <= m; i++)
        scanf("%d %d %d",&d[i],&s[i],&t[i]);

    if(check(m)) {
        cout << "0" << endl;
        return 0;
    }

    int l = 1;
    int r = m;
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(check(mid))
            l = mid + 1;
        else
            r = mid;
    }
    //二分第一个不行的

    cout << "-1" << endl << r << endl;
    //答案就是r，此时l = r都是第一个不行的

    return 0;
}

bool check(int mid){
    //差分当前剩余的教室数量
    for(int i = 1; i <= n; i++)
        b[i] = w[i] - w[i-1];
    for(int i = 1; i <= mid; i++){
        //s[i]天借走了d[i]个教室
        b[s[i]] -= d[i];
        //t[i]天还回了d[i]个教室
        b[t[i] + 1] += d[i];
    }

    for(int i = 1; i <= n; i++){
        //求差分数组的前缀和，就是当前剩余教室的数量
        b[i] += b[i-1];
        //当剩余教室的数量小于0时表示不行
        if(b[i] < 0)
            return false;
    }

    return true;
}
