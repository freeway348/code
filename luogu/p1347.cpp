#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n,m;
const int N = 1010, M = N * N;
int d[N], g[N];
int h[N], e[M],ne[M],idx;
int q[N];

void add(int a, int b) // a --> b
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++, g[b] ++;
}

int toport()
{
    int f = 0;
    int cnt = 0;
    memcpy(d, g, sizeof g);
    memset(q, 0, sizeof q);
    int hh = 0, tt = -1;

    for (int i = 1; i <= n; i ++)
        if (!d[i])
            q[++ tt] = i, cnt ++;
    if (cnt > 1) f = 1;

    while(hh <= tt)
    {
        cnt = 0;
        int t = q[hh ++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            d[j] --; // 去掉该节点
            if (!d[j])
                q[++ tt] = j, cnt ++;
            
        }
        if (cnt > 1) f = 1;
    }
    if (tt < n - 1) return -1; // 存入点的数量少于 n，则说明条件有矛盾---------存在入度不为 0 的数 ---------- 成环
    if (f) return 1; // 条件不足
    return 0; // 正常情况
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    bool flag = false;
    for (int i = 1; i <= m; i ++)
    {
        char A,B;
        scanf(" %c<%c",&A, &B);
        add(A - 'A' + 1, B - 'A' + 1);
        int x = toport();
        if (!flag && x == -1)
        {
            cout << "Inconsistency found after " << i << " relations.";
            flag = true;
        }
        else if (!x && !flag)
        {
            cout << "Sorted sequence determined after " << i << " relations: ";
            for (int i = 0; i < n; i ++)
                cout << (char)(q[i] + 'A' - 1);
            cout << ". " << endl;
            flag = true;
        }
    }
    if (!flag) cout << "Sorted sequence cannot be determined." << endl;
    return 0;
}