// 题：acwing， 有向图的拓扑序列
// 拓扑序列 --------- 图的宽搜的应用
// 图的拓扑序列------------有向图
// 有向无环图一定存在 拓扑序列 ，所以又被称为拓扑图
// 环 一定不存在 拓扑序列
// 有向无环图必定存在一个入度为 0 的点----------即：起点
// 本质还是宽搜
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;
int h[N],e[N],ne[N],idx; 
int q[N],d[N]; // q 数组存储的是拓扑序列，d 数组存储的是入度
int n,m;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

bool topsort() // 因为在有向无环图中，入度小的点肯定在更前面，所以 q 数组中存的也是符合拓扑序列要求的序列数
{
    int hh = 0, tt = -1; 
    // tt 取 -1 是因为：如果在 1 ~ n 中只存在一个入度为 0 的起点，则此时 q 数组（模拟队列）中仅有一个元素，所以刚好符合 hh <= tt 的条件
    // 如果从 0 开始，则会导致 q 数组中只有一个元素，while循环却要至少循环两次
    for (int i = 1; i <= n; i ++)
        if (!d[i]) // 如果入度为 0
            q[++ tt] = i; // 队尾入队

    while (hh <= tt)
    {
        int t = q[hh ++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            d[j] --; // 每找到该点的一个入度（上一个点），就将其入度 - 1
            if (!d[j]) // 最终如果入度变为 0， 则说明不是环
                q[++ tt] = j;
        }
    }
    return tt == n - 1;
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
        d[b] ++;
    }
    if (topsort())
    {
        for (int i = 0; i < n; i ++) cout << q[i] << ' ';
    }
    else cout << -1 << endl;
    return 0;
}
