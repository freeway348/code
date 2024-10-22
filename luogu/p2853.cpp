#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010, M = 1e4 + 10;
int k,m,n;
int a[N];
int e[M], ne[M], h[N], idx;
int ans;
int res;
bool g[N];

void add(int x, int y)
{
    e[idx] = y, ne[idx] = h[x], h[x] = idx ++;
}

void dfs(int u)
{
    for (int i = h[u]; i != -1; i = ne[i]) // 遍历所有能走到第 u 个牧场的牧场
    {
        int j = e[i]; 
        if (g[j]) continue;
        g[j] = true; // 找过第 j 个牧场了，必须要先标记，要不然可能会多次找到牧场 j 导致无效操作过多，递归深度超限导致爆栈
        dfs(j); // 往下找
        
    }
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> k >> n >> m;
    for (int i = 1; i <= k; i ++)
    {
        int x;
        cin >> x;
        a[x] ++; //  x 号牧场有多少头牛
    }
    for (int i = 1; i <= m; i ++)
    {
        int x,y;
        cin >> x >> y; // 牛能从 x 走向 y 牧场，如果要找到所有牛都能到达的终点牧场，就要从后往前推导 
        add(y, x);
    }
    for (int i = 1; i <= n; i ++) // 遍历所有 n 个牧场，查找出符合条件的牧场个数
    {
        bool f = false;
        memset(g, false, sizeof g);
        dfs(i);
        g[i] = true;
        for (int j = 1; j <= n; j ++) // 遍历所有牧场，查看是否所有有牛的牧场都被遍历到了
            if (a[j] && !g[j])
            {
                f = true;
                break;
            } 
        if (!f) ans ++;
    }
    cout << ans << endl;
    return 0;
}