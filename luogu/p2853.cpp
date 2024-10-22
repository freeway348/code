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
    for (int i = h[u]; i != -1; i = ne[i]) // �����������ߵ��� u ������������
    {
        int j = e[i]; 
        if (g[j]) continue;
        g[j] = true; // �ҹ��� j �������ˣ�����Ҫ�ȱ�ǣ�Ҫ��Ȼ���ܻ����ҵ����� j ������Ч�������࣬�ݹ���ȳ��޵��±�ջ
        dfs(j); // ������
        
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
        a[x] ++; //  x �������ж���ͷţ
    }
    for (int i = 1; i <= m; i ++)
    {
        int x,y;
        cin >> x >> y; // ţ�ܴ� x ���� y ���������Ҫ�ҵ�����ţ���ܵ�����յ���������Ҫ�Ӻ���ǰ�Ƶ� 
        add(y, x);
    }
    for (int i = 1; i <= n; i ++) // �������� n �����������ҳ�������������������
    {
        bool f = false;
        memset(g, false, sizeof g);
        dfs(i);
        g[i] = true;
        for (int j = 1; j <= n; j ++) // ���������������鿴�Ƿ�������ţ������������������
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