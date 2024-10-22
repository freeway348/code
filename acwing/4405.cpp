#include <iostream>
using namespace std;
#define ll long long
const int N = 5e2 + 10;
int n,m,k;
int p[N][N];

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
        {
            cin >> p[i][j];
            p[i][j] += p[i - 1][j];//求列的前缀和（每列）
        }
    //界定上下边界，即从第 1 ~ n 行
    //由于p[i][j]表示第j列的前缀和，所以只要从左到右求p[1 ~ i][j]的和，就能求出矩阵p[i][j]的总和
    ll res = 0;
    for (int i = 1;i <= n; i ++)
        for (int j = i; j <= n; j ++)
            for (int l = 1, r = 1, sum = 0; r <= m; r ++)//双指针
            {
                sum += p[j][r] - p[i - 1][r];//加右边界的一列前缀和
                while (sum > k)
                {
                    sum -= p[j][l] - p[i - 1][l];//减去最左的一列前缀和
                    l ++ ;
                }
                res += r - l + 1;
            }
    cout << res;
    return 0;
}