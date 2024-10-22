#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n,m;
int e[N],ne[N],h[N],idx;
int q[N];
int st[N];
int res;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void bfs(int x)
{
    int hh= 0, tt = 0;
    q[0] = x;
    while(hh <= tt)
    {
        int t = q[hh ++];
        if (!st[t]) st[t] = x;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            
            if (!st[j])
            {
                q[++ tt] = j;
            }
        }
    }
}

int main()
{  
    memset(h,-1,sizeof h); // 记得初始化
    cin >> n >> m;
    for (int i = 0; i < m; i ++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(b,a); // 反向建图
    }
    for (int i = n; i > 0; i --)
    {
        bfs(i);
    }
    for (int i = 1; i <= n; i ++)
        cout << st[i] << ' ';
    return 0;
}