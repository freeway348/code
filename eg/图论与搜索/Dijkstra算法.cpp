// Dijkstra算法求最短路 
// 题目：给定一个 n 个点，m 条边的有向图，图中可能存在重边和自环，所有边权均为正数，求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 -1
// 范围：1 <= n <= 500; 1 <= m <= 1e5 ---------- 稠密图 --------  邻接矩阵
// 输入：第一行包括两个整数 n 和 m，接下来 m 行包含三个整数 x,y,z，表示点 x 和点 y 之间有一条有向边，其边权（边长）为 z
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 510;
int n,m;
int g[N][N]; // g[a][b]:记录点 a 到点 b 的边长
int dist[N]; // dist[i]： 1 号点到 i 号点的最短距离
bool st[N]; // st[i]：记录点 i 是否已经为最短距离 

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0; // 1 号点是起点

    for (int i = 0; i < n; i ++) // 循环 n 次，将 1 号点到这 n 个点的最短距离都算出来
    {
        int t = -1; // 每次循环找到往下一步的最短距离
        for (int j = 1; j <= n; j ++) // 枚举每一个点
            if (!st[j] && (t == -1 || dist[t] > dist[j])) // 未被 st 标记的距离最近的点
                t = j; // 用 t 更新其他点的距离
        
        st[t] = true;

        for (int j = 1; j <= n; j ++)
            dist[j] = min(dist[j],dist[t] + g[t][j]); // 枚举每一个点，判断从 1 号点出发，经过中间点 t 的路线与直接到 j 号点的距离哪个更短
    }
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while(m --)
    {
        int a,b,c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c); // 解决重边问题
    }
    int t = dijkstra();
    cout << t << endl;
    return 0;
}