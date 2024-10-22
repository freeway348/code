#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e6 + 10;
int n;
int idx,e[N],ne[N],h[N],w[N];
int ans;
int q[N], d[N]; // q �����ˣ�d ����� 
int f[N]; // f[i] : �����㣨���Ϊ 0 �ĵ㵽 �� i �������������ʱ��)

void add(int a, int b, int v) // a -> b
{
    e[idx] = b, ne[idx] = h[a], d[b] ++, h[a] = idx ++; // ��ɹ��� a �����ʱ��Ϊ v
}

void solve()
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i ++)
        if (!d[i]) // ������Ϊ 0
        {
            q[++ tt] = i; // ��β���
            f[i] = w[i];
        }
    
    while(hh <= tt)
    {
        int t = q[hh ++];
        for (int i = h[t]; i != -1; i = ne[i]) // ÿ��ȡͬʱ�����
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
            add(b, a, v); // b ָ�� a
    }
    solve();
    for (int i = 1; i <= n; i ++)
        ans = max(ans, f[i]);
    cout << ans;
    return 0;
}