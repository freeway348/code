// 题：acwing 874.图中点的层次
// 给定 n 个点，m 条边，有可能存在重边和自环，所有边长度为 1 ，编号为 1 ~ n，求出 1 号到 n 号点的最短距离，如果从 1 走不到 n，则输出 -1
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100010, M = 2 * N;
int h[N],e[M], ne[M], idx;
int n,m;
int d[N],q[N]; // d 记录的是 1 号点到该点的距离， q 是队列中存储的点


void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int bfs()
{
    int hh = 0, tt = 0;
    q[0] = 1; 
    memset(d, -1, sizeof d);
    d[1] = 0; 
    while(hh <= tt)
    {
        int t = q[hh ++];

        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (d[j] == -1)
            {
                d[j] = d[t] + 1;
                q[++ tt] = j;
            }
        }
    }
    return d[n];
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    
    for (int i = 0; i < m; i ++)
    {
        int a,b;
        cin >> a >> b;
        add(a,b);
    }

    cout << bfs() << endl;

    return 0;
}