#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;
const int N = 5010, M = 500010, mod = 80112002;

LL idx, e[M], ne[M], h[N];
LL d[N],p[N]; // 入度和出度
LL q[N];
LL f[N]; 
LL n,m;
LL sum;

void add(int x, int y)
{
    e[idx] = y, ne[idx] = h[x], h[x] = idx ++, d[y] ++, p[x] ++;
}

void toport()
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i ++)
    {
        if (!d[i]) // 入度为 0 
            q[++ tt] = i, f[i] = 1; // 生产者
    }
    while(hh <= tt)
    {
        int t = q[hh ++];
        for (int i = h[t]; i != -1; i = ne[i]) // 找下一级消费者
        {
            int j = e[i];
            d[j] --;
            f[j] = (f[j] + f[t]) % mod;
            if (!d[j])
                q[++ tt] = j;
        }
    }
    for (int i = 1; i <= n; i ++)
        if (!p[i]) // 食物链顶端的消费者
            sum = (sum + f[i]) % mod;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        int x,y;
        cin >> x >> y;
        add(x,y);
    } 
    toport();
    cout << sum;
    return 0;
}