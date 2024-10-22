// Dijkstra算法求最短路 
// 题目：给定一个 n 个点，m 条边的有向图，图中可能存在重边和自环，所有边权均为正数，求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 -1
// 范围：1 <= n <= 2e3; 1 <= m <= 1e5,边长绝对值不超过 1e5  
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
int dist[N],cnt[N]; // dist[i]： 1 号点到 i 号点的最短距离; cnt[i] : 到第 i 点的最短路经过了多少条边
bool st[N]; 

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx, idx ++;
}

bool spfa()
{
     
    queue<int> q;
    for(int i = 1; i <= n; i ++)
    {
        st[i] = true;
        q.push(i); // 将所有点均放入初始点集，以判断每个点为起点的路径是否存在负环
    }
    while(q.size())
    {
        auto t = q.front();
        q.pop();

        st[t] = false; // 出队之后置为 false

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1; // 如果更新了，说明比原来的路径还多一条边
                if (cnt[j] >= n) return true; // 如果存在n 条边，则说明有 n + 1 个点，必定有一个点出现了两次，则说明出现负环
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
                
        }
        
    }
    return false;
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
    if (spfa()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}