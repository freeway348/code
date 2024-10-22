#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#define mod 100003
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

const int N = 1e6 + 10, M = 2e7 + 10;
int idx,e[M],ne[M],h[M],w[M],dist[M];
int n,m;
int ans[M];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = 1, h[a] = idx ++; 
}

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0; // 1 号点是起点
    ans[1] = 1;
    priority_queue<PII,vector<PII>, greater<PII> > heap;
    heap.push({0,1}); // first 存权值（从 1 号点到该点的最短距离）,second 存第 i 号点 ---------- 因为小根堆的排序是先将 first 从小到大排完之后再排second
    
    while(heap.size())
    {
        auto t = heap.top(); // 每次找到一个点最短距离
        heap.pop();
        int ver = t.second, distance = t.first;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                ans[j] = ans[ver]; // 如果最短路更新，则最短路的条数也要更新
                heap.push({dist[j],j});

            }
            else if (dist[j] == distance + w[i])
            {
                ans[j] = (ans[j] + ans[ver]) % mod; // 如果从点 ver 仍然能走到点 j 并且是最短路，则将其加上
            }
        }

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m --)
    {
        int a,b;
        cin >> a >> b;
        add(a,b);
        add(b,a);
    }
    dijkstra();
    for (int i = 1; i <= n; i ++)
        cout << ans[i] << endl;
    return 0;
}