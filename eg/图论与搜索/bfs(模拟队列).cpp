//����n,m�����Թ���n�У�m�У���Ҫ��������(0,0)�ߵ��յ�(n-1,m-1)����̾���
//ʹ�ö������洢���߹����ӵľ���
#include <bits/stdc++.h>
using namespace std;
#define N 110
typedef pair<int,int> PII;
int g[N][N];//��¼�ø����Ƿ����ߣ���¼������ӣ�
int d[N][N];//��¼���ø��ӵľ���
int n,m;
PII q[N * N];//��¼�߹�������
int bfs()
{
    q[0] = {0,0};
    int hh = 0, tt = 0;
    memset(d,-1,sizeof d );
    d[0][0] = 0;
    int dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};
    while (hh <= tt)
    {
        auto t = q[hh ++];//���������е�ÿһ��Ԫ��ֱ��������ȫ
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