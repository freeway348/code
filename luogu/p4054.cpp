#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 310;
int tr[N][N][N]; // tr[i][j][k] : [1,1] ~ [i,j] 中所有权值为 k 的格子的总数
int p[N][N]; // 初始权值
int n,m;
int q;

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int y, int k, int c)
{
    for (int i = x; i <= n; i += lowbit(i))
        for (int j = y; j <= m; j += lowbit(j))
            tr[i][j][k] += c;
}

long long query(int x, int y, int k)
{
    long long res = 0;
    for (int i = x; i; i -= lowbit(i))
        for (int j = y; j; j -= lowbit(j))
            res += tr[i][j][k];
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
        {
            cin >> p[i][j];
            add(i,j,p[i][j],1);
        }
    cin >> q;
    while(q --)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int a,b,c;
            cin >> a >> b >> c;
            add(a, b, p[a][b], -1);
            p[a][b] = c;
            add(a, b, p[a][b], 1);
        }
        else if (x == 2)
        {
            int x1,x2,y1,y2,c;
            cin >> x1 >> x2 >> y1 >> y2 >> c;
            cout << query(x1 - 1,y1 - 1,c) + query(x2,y2,c) - query(x1 - 1,y2,c) - query(x2,y1 - 1,c) << endl; // 注意特异点，即边界问题
        }
    }
    return 0;
}