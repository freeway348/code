#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e6 + 10;
int n;
int idx,e[N],ne[N],h[N],w[N];
int ans;
int q[N], d[N]; // q 存拓扑，d 存入度 
int f[N]; // f[i] : 存从起点（入度为 0 的点到 点 i 任务完成所花的时间)

void add(int a, int b, int v) // a -> b
{
    e[idx] = b, ne[idx] = h[a], d[b] ++, h[a] = idx ++; // 完成工作 a 所需的时间为 v
}

void solve()
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i ++)
        if (!d[i]) // 如果入度为 0
        {
            q[++ tt] = i; // 队尾入队
            f[i] = w[i];
        }
    
    while(hh <= tt)
    {
        int t = q[hh ++];
        for (int i = h[t]; i != -1; i = ne[i]) // 每次取同时段最久
        {
            int j = e[i];
            d[j] --;
            if (!d[j])
                q[++ tt] = j;
            f[j] = max(f[j], f[t] + w[j]);
        }
    }
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n; i ++)
    {
        int a,v,b;
        cin >> a >> v;
        w[a] = v;
        while(cin >> b, b != 0)
            add(b, a, v); // b 指向 a
    }
    solve();
    for (int i = 1; i <= n; i ++)
        ans = max(ans, f[i]);
    cout << ans;
    return 0;
}