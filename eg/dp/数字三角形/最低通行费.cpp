// acwing 1018
#include <iostream>
#include <cstring>

using namespace std;

const int N = 110, INF = 1e9;

int a[N][N], f[N][N];
int n;

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            scanf("%d", &a[i][j]);

    // 初始化为正无穷
    memset(f,0x3f,sizeof f);            
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
        {
            if (i == 1 && j == 1) f[i][j] = a[i][j];
            else f[i][j] = min(f[i - 1][j], f[i][j - 1]) + a[i][j]; 
        }
    // 也可以不赋初值0x3f，如下写法
    /*
    全局变量：const int INF = 1e9 // 无穷大

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (i == 1 && j == 1) f[i][j] = a[i][j]; // 特判左上角的点
            else 
            {
                f[i][j] = INF;
                if (i > 1) // 不在第一行时，才能从上边下来
                    f[i][j] = min(f[i][j], f[i - 1][j] + a[i][j]);
                if (j > 1) // 不在第一列时，才能从左边过来
                    f[i][j] = min(f[i][j], f[i][j - 1] + a[i][j]);
            }
        
    
    */

    printf("%d", f[n][n]);

    return 0;
}