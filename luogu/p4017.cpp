#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;
const int N = 5010, M = 500010, mod = 80112002;

LL idx, e[M], ne[M], h[N];
LL d[N],p[N]; // ��Ⱥͳ���
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
        if (!d[i]) // ���Ϊ 0 
            q[++ tt] = i, f[i] = 1; // ������
    }
    while(hh <= tt)
    {
        int t = q[hh ++];
        for (int i = h[t]; i != -1; i = ne[i]) // ����һ��������
        {
            int j = e[i];
            d[j] --;
            f[j] = (f[j] + f[t]) % mod;
            if (!d[j])
                q[++ tt] = j;
        }
    }
    for (int i = 1; i <= n; i ++)
        if (!p[i]) // ʳ�������˵�������
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