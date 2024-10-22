#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 110, M = N * N;
int idx,h[N], e[M],ne[M];
int d[N]; // 入度
int q[M]; // 队列
int n;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++, d[b] ++;
}

void toport()
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i ++)
        if (!d[i])
            q[++ tt] = i;
    while(hh <= tt)
    {
        int t = q[hh ++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            d[j] --;
            if (!d[j])
                q[++ tt] = j;
        }
    }
    for (int i = 0; i < n; i ++)
        cout << q[i] << ' ';
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        int x;
        while(cin >> x, x != 0)            
            add(i, x);
            
    }
    toport();
    return 0;
}