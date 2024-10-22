//输入n,m代表迷宫有n行，m列，现要求出从起点(0,0)走到终点(n-1,m-1)的最短距离
//使用队列来存储已走过格子的距离
#include <bits/stdc++.h>
using namespace std;
#define N 110
typedef pair<int,int> PII;
int g[N][N];//记录该格子是否能走（记录输入格子）
int d[N][N];//记录到该格子的距离
int n,m;
PII q[N * N];//记录走过的坐标
int bfs()
{
    q[0] = {0,0};
    int hh = 0, tt = 0;
    memset(d,-1,sizeof d );
    d[0][0] = 0;
    int dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};
    while (hh <= tt)
    {
        auto t = q[hh ++];//遍历队列中的每一个元素直至遍历完全
        for (int i = 0;i < 4;i ++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (d[x][y] == -1 && g[x][y] == 0 && x >= 0 && x < n && y >= 0 && y < m)
            {
                d[x][y] = d[t.first][t.second] + 1;
                q[++ tt] = {x,y};
            }
        }
    }
    return d[n-1][m-1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n;i ++)
        for (int j = 0; j < m ; j ++)
            cin >> g[i][j];
    cout << bfs() << endl;
    return 0;
}