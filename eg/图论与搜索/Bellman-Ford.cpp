// 题目：给定 n 个点 m 条边的有向图，可能存在重边和自环，边权可能为负数，求出从 1 号点到 n 号点的最多经过 k 条边的最短距离，如果无法到达 n 号点，则输出 -1
// 数据范围： 1 <= n,k <= 500; 1 <= m <= 1e4,任意边长的绝对值不超过 1e4
// 存储方式：均可，只要能遍历到所有边就可以
// 如果有负权回路，则最短路可能不存在(例如：回路为： 1,2，-4，则每经过一次回路，最短距离就会更短，所以在该回路可能进入死循环)
// n 次迭代 ---------- 能找到经过 n 条边的最短距离
// Bellman-Ford算法也可以用来找负环 ------- 前 n - 1 次更新已找到最短距离，如果第 n 次仍能更新最短距离，此时： n 条边-----说明有 n + 1 个点，则必存在环，并且由于更新后的距离比最短距离还短，说明这个环是负环
// 一般用SPFA算法来找负环，Bellman-Ford算法时间复杂度太高
// Bellman-Ford算法可得三角不等式：dist[b] <= dist[a] + w 
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 100010;

int n,m,k;
int dist[N],backup[N];

struct Edge
{
    int a,b,w;
}edges[M];

int bellman_ford()
{
    memset(dist, 0x3f,sizeof dist);
    dist[1] = 0; // 定义起点
    for (int i = 0; i < k; i ++) // 最多经过 k 条边
    {
        memcpy(backup,dist,sizeof dist);
        for (int j = 0; j < m; j ++) // 遍历所有边
        {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b],backup[a] + w); // 松弛操作
            // 用上一次循环更新的结果来更新这一次循环，避免一次循环中的更新出现连锁情况----------例如：我们只求经过一条边的最短路
            // 但 1 -> 2 = 1
            // 2 -> 3 = 1 ,
            // 1 -> 3 = 3
            // 此时如果用dist 来更新，就会导致 1 -> 3 的最短路是 1 -> 2 -> 3, 而不是 1 -> 3,这就用了两条边，这不是我们想要的，所以需要将 dist 数组备份到 backup 中

        }
    }
    if (dist[n] > 0x3f3f3f3f / 2) return -1; // 如果 dist[x] = 0x3f3f3f3f, dist[n] = 0x3f3f3f3f, 但 x -> n = - 50,则 dist[n] 就会被更新为：0x3f3f3f3f - 50 
    // 并且如果找不到到 n 号点的路径，例如：1 号点与其他点之间没有边，但其他点之间都有边，并且能到 n 号点，此时考虑极端情况：n 和 m 取最大：500 条权值为 -1e4，计算可知，结果为 -5e6，则到dist[n] = 0x3f3f3f3f - 5e6
    return dist[n];
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i ++)
    {
        int a,b,w;
        cin >> a >> b >> w;
        edges[i] = {a,b,w};
    }
    int t = bellman_ford();
    if (t == -1) cout << "impossible" << endl;
    else cout << t << endl;
    return 0;
}