#include <iostream>
#include <algorithm>

using namespace std;

const int N = 150;

int n;
int f[N][N];
int a[N][N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
        {
            cin >> a[i][j];
        }

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            f[i][j] = a[i][j] + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1]; // 二维前缀和
    
    int sum = -2e9;
    // 枚举所有矩形左上角和右下角坐标的组合
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            for (int x = i + 1; x <= n; x ++)
                for (int y = j + 1; y <= n; y ++)
                {
                    sum = max(sum, f[x][y] + f[i - 1][j - 1] - f[i - 1][y] - f[x][j - 1]);
                }
    cout << sum;
    return 0;
}