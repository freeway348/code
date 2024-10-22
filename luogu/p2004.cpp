#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 1010;
LL g[N][N];
LL f[N][N];

int main()
{
    int n,m,c;    
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
        {
            cin >> g[i][j];
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + g[i][j]; // 从 1,1 到 i，j 的面积和
        }
    LL maxn = -2e9;
    int x,y;
    for (int i = 1; i + c - 1 <= n; i ++)
        for (int j = 1; j + c - 1 <= m; j ++)
        {
            if (maxn < f[i + c - 1][j + c - 1] - f[i + c - 1][j - 1] - f[i - 1][j + c - 1] + f[i - 1][j - 1]) // 要注意，数组中存的是点，不是格子
            {
                maxn = f[i + c - 1][j + c - 1] - f[i + c - 1][j - 1] - f[i - 1][j + c - 1] + f[i - 1][j - 1];
                x = i, y = j;
            }

        }
    cout << x << ' ' << y << endl;

    return 0;
}