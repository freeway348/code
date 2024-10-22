#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e6 + 10;
int idx, e[N], ne[N], w[N], h[N];
int n, d;
int ans;
int f[N],q[N]; // f 记录的是 1 号点到该点的距离， q 是队列中存储的点
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void solve()
{
    int hh = 0, tt = 0;
    q[0] = 1;
    memset(f, -1, sizeof f);
    f[1] = 0;
    while(hh <= tt)
    {
        int t = q[hh ++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (f[j] == -1) // 之前没走到过
            {
                f[j] = f[t] + 1;
                q[++ tt] = j;
                
            }
        }
        if (!st[t] && f[t] <= d && f[t] > 0)
        {
            st[t] = true;
            ans ++;
        }
    }
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> d;
    for (int i = 1; i < n; i ++)
    {
        int a,b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    solve();
    cout << ans;
    return 0;
}