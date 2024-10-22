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
bool st[N]; 

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx, idx ++;
}

int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0; // 1 号点是起点
    queue<int> q;
    q.push(1); 
    st[1] = true; // st[i]: 记录点 i 是否在队列中，防止队列中放入重复元素 
    while(q.size())
    {
        auto t = q.front();
        q.pop();

        st[t] = false; // 出队之后置为 false

        for (int i = h[t]; i != -1; i = ne[i]) // 找后继点
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i]; // 只有最短距离更新了，这个点才能再放到队列中，以求得更短的距离
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
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
    int t = spfa();
    if (t == -1) cout << "impossible" << endl;
    else cout << t << endl;
    return 0;
}