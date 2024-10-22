// 二分图-----------当且仅当图中不含奇数环（环中的边数是奇数）
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10, M = 2e6 + 10; // N -------- 点 ， M --------- 边 （无向图，所以边是两倍)
int idx,e[M],ne[M],h[N];
int color[N]; // 记录每个点的色块
int n,m;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool dfs(int u, int c)
{
    color[u] = c; // 染色

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!color[j])
        {
            if (!dfs(j,3 - c)) return false; // 联通块中存在奇数环，则错误 -------- 非二分图
        }       
        else if (color[j] == c) return false; // 两条相邻边的颜色相同，则错误 
    }

    return true;
}


int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while(m --)
    {
        int a,b;
        cin >> a >> b;
        add(a,b),add(b,a);
    }

    bool flag = true;
    for (int i = 1; i <= n; i ++)
        if (!color[i]) // 如果第 i 个点没被染色，就进入dfs将这个点所在的联通块染色
        {
            if (!dfs(i,1)) // 如果 i 号点所在的这个联通块是奇数环，则不可能是二分图，所以将flag 标记为false，并退出循环
            {
                flag = false;
                break;
            }
        }
    if (flag) cout << "是二分图" << endl;
    else cout << "不是二分图" << endl;
    return 0;
}