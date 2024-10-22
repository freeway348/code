// Dijkstra算法求最短路 
// 题目：给定一个 n 个点，m 条边的有向图，图中可能存在重边和自环，所有边权均为正数，求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 -1
// 范围：1 <= n <= 1e6; 1 <= m <= 1e6 ---------- 稀疏图 ----------- 邻接表
// 输入：第一行包括两个整数 n 和 m，接下来 m 行包含三个整数 x,y,z，表示点 x 和点 y 之间有一条有向边，其边权（边长）为 z
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int,int> PII;
const int N = 100010;
int n,m;
int idx,e[N],ne[N],h[N],w[N]; // w 存权值
int dist[N]; // dist[i]： 1 号点到 i 号点的最短距离
bool st[N]; // st[i]：记录点 i 是否已经为最短距离 

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx, idx ++;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0; // 1 号点是起点

    priority_queue<PII,vector<PII>, greater<PII> > heap;
    heap.push({0,1}); // first 存权值（从 1 号点到该点的最短距离）,second 存第 i 号点 ---------- 因为小根堆的排序是先将 first 从小到大排完之后再排second
    
    while(heap.size())
    {
        auto t = heap.top(); // 每次找到一个点最短距离
        heap.pop();
        int ver = t.second, distance = t.first;
        if (st[ver]) continue;

        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j],j});
            }
        }

    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m --)
    {
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
    }
    int t = dijkstra();
    cout << t << endl;
    return 0;
}