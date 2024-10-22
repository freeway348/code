//棋盘问题，差分每次取反 +1 操作，再最后输出该点的 棋子颜色模2 的值，0为白，1为黑
#include <iostream>
using namespace std;
const int N = 2e3 + 10;
typedef long long LL;
int p[N][N];//原本值也为1，故原数组作差分数组处理

int main()
{
    int n,m;
    int x1,x2,y1,y2;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        p[x1][y1] += 1;
        p[x2 + 1][y1] -= 1;
        p[x2 + 1][y2 + 1] += 1;
        p[x1][y2 + 1] -= 1;
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
            cout << p[i][j] % 2;
        }
        cout << '\n';
    }
    return 0;
}