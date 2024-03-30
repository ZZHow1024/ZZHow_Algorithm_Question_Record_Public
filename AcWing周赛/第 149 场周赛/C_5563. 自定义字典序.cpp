// C_5563. 自定义字典序
// Created by DNX on 2024/3/30.
#include <iostream>
#include <cstdio>

#define N 110
#define M 30

using namespace std;

bool work(string &a, string &b);
bool topSort();

int n;
string s[N];
bool g[M][M];
int q[M], d[M];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 1; i < n; i++)
        if(!work(s[i - 1], s[i]))
        {
            puts("Impossible");
            return 0;
        }

    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            if(g[i][j])
                d[j]++;

    if (!topSort())
        puts("Impossible");
    else {
        for (int i = 0; i < 26; i++)
            cout << (char) (q[i] + 'a');
    }

    return 0;
}

bool work(string &a, string &b) {
    for (int i = 0; i < a.size() && i < b.size(); i++)
        if (a[i] != b[i]) {
            int x = a[i] - 'a', y = b[i] - 'a';
            g[x][y] = true;
            return true;
        }

    return a < b;
}

bool topSort() {
    int hh = 0;
    int tt = -1;
    for (int i = 0; i < 26; i++)
        if (!d[i])
            q[++tt] = i;

    while (hh <= tt) {
        int t = q[hh++];
        for (int i = 0; i < 26; i++)
            if (g[t][i]) {
                d[i]--;
                if (!d[i])
                    q[++tt] = i;
            }
    }

    return tt == 25;
}
