// 大致题目:给定一个 n 个点（1 ~ n） m 条边的无向图，图中可能存在 重边 和 自环，边权可能为负数;求最小生成树的边权权重之和，如果不存在则输出 impossible


#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510,INF = 0x3f3f3f3f;

int g[N][N]; // g[a][b] : 邻接矩阵存点 a 到点 b 的距离
int dist[N]; // dist[j] : 存的是点 j 到已存入最小生成树的点的集合的距离
int n,m; 
bool st[N]; // st[j] : 判断点 j 是否放入最小生成树的点集中

int prim()
{
    memset(dist, 0x3f, sizeof dist);

    int res = 0;

    for (int i = 0; i < n; i ++) // 迭代 n 次，更新 n - 1 条边
    {
        int t = -1;
        for (int j = 1; j <= n; j ++) // 遍历每一个点
            if (!st[j] && (t == -1 || dist[t] > dist[j])) // 找到集合外 离集合最近的点
                t = j;
        
        if (i && dist[t] == 0x3f3f3f3f) return INF; // 如果集合外的点距离集合的最短距离也是无穷大，则说明无法构成最小生成树

        if (i) // 因为 i = 0 这一次循环是用于更新所有点到 1 号点的距离，这时 dist 数组还未更新，内容均为无穷大，所以不能取
            res += dist[t];

        for (int j = 1; j <= n; j ++)  dist[j] = min(dist[j],g[t][j]); // 点 t 已经加入到最小生成树的点集中，这里的作用是更新所有点到最小生成树的点集的距离

        st[t] = true;
    }
    return res;

}

int main()
{
    cin >> n >> m;

    memset(g, 0x3f, sizeof g);

    while(m --)
    {
        int a,b,c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b],c);
    }

    int t = prim();

    if (t == 0x3f3f3f3f) cout << "impossible" << endl;
    else cout << t << endl;

    return 0;
}