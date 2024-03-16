// 5556. 牛的语言学(超时)
// Created by DNX on 2024/3/16.
#include <iostream>
#include <cstring>

#define N 10010

using namespace std;

void solve(int i, int u, int num);
bool check();
void mergeSort(int l, int r);

char str[N];
char tmp[5];
char ans[N][5];
int cnt;
char t[N][5];
char tmp2[5];

int main() {
    cin >> str;

    int len = (int) strlen(str);
    solve(len, 2, 0);
    solve(len, 3, 0);

    mergeSort(0, cnt - 1);

    cout << cnt << endl;
    for (int i = 0; i < cnt; i++)
        cout << ans[i] << endl;

    return 0;
}

void solve(int i, int u, int num)
{
    if(i <= 4 + u)
        return;
    tmp2[2] = '\0';
    int k = 0;
    for(int j = 0; j < num; j++, k++)
        tmp2[k] = str[i+j];

    i -= u;
    if(u == 2)
    {
        tmp[2] = '\0';
        tmp[0] = str[i];
        tmp[1] = str[i + 1];
        if(!strcmp(tmp, tmp2))
            return;
        if (check())
            strcpy(ans[cnt++], tmp);
    }
    if(u == 3)
    {
        tmp[0] = str[i];
        tmp[1] = str[i + 1];
        tmp[2] = str[i + 2];
        if(!strcmp(tmp, tmp2))
            return;
        if (check())
            strcpy(ans[cnt++], tmp);
    }

    solve(i, 2, u);
    solve(i, 3, u);
}

bool check() {
    for (int i = 0; i < cnt; i++)
        if (!strcmp(tmp, ans[i]))
            return false;

    return true;
}

void mergeSort(int l, int r) {
    if(l >= r)
        return;

    int mid = (l + r) >> 1;

    mergeSort(l, mid);
    mergeSort(mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (strcmp(ans[i], ans[j]) <= 0)
            strcpy(t[k++], ans[i++]);
        else
            strcpy(t[k++], ans[j++]);
    }

    while (i <= mid)
        strcpy(t[k++], ans[i++]);

    while (j <= r)
        strcpy(t[k++], ans[j++]);

    for (i = l, j = 0; i <= r; i++, j++)
        strcpy(ans[i], t[j]);
}
