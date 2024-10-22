//能在O(n^3)的时间复杂度下求解 n 个多项式方程组
//先将这 n 个方程组的每个幂级次数的系数和等号右边的结果组成一个矩阵（系数矩阵与常数矩阵组成的增广矩阵）
//三种等价变换(初等行列变换)：
//（1）把某一行乘一个非零的数
//（2）交换某两行
//（3）把某行的若干倍加到另一行
//高斯消元: 先将系数矩阵消成上三角矩阵，再从下到上回代求解(用的是增广矩阵，只是其中的常数矩阵只随系数矩阵变换，不会自主变换)
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
const double eps = 1e-6;//不能设置成int型，否则判断是否极小趋近于 0 时会无法判断，因为int型会将其四舍五入为 0 ，而不是 1e-6

const int N = 110;
double a[N][N];
int n;

int gauss()//将矩阵变为上三角形后再从下往上回代求解
{
    int r,c;
    for (c = 0, r = 0; c < n; c ++)// r 表示前 r - 1 行均以完成变换，现正在选择第 r 行进行变换, c 表示第 c 列
    {
        int t = r;
        for (int i = r + 1; i < n; i ++)//在第 c 列中选择最大的数所在的行，将其换到第 r 行
            if (fabs(a[i][c]) > fabs(a[t][c]))//求浮点数的绝对值
                t = i;

        if (fabs(a[t][c]) < eps)//如果第 c 列余下的 (r ~ (n - 1) 行均为 0 ，则跳过该列
            continue;

        for (int i = c; i <= n; i ++) swap(a[r][i],a[t][i]);//将第 r 行与第 t 行(满足条件的)交换
        for (int i = n; i >= c; i --) a[r][i] /= a[r][c];//将第 r 行的第 c 个数变为 1 (主元)
        for (int i = r + 1; i < n; i ++)//将第 (r + 1) ~ (n - 1) 行第 c 列均变为 0
            if (fabs(a[i][c]) > eps)//如果不为 0 则进行操作，为 0 则不进行操作
            {
                for (int j = n; j >= c; j --)
                //因为将第 i 行第 c 列的数变为 0 的操作就是：a[i][c] -= a[i][c] * a[r][c]
                    a[i][j] -= a[r][j] * a[i][c];// 所以将第 i 行第 j 列的数变为 0 的操作就是：a[i][j] -= a[i][c] * a[r][j]
            }

        r ++;
    }
    if (r < n) //有一行的主元为 0
    {
        for (int i = r; i < n; i ++)
            if (fabs(a[i][n]) > eps)//只存在 r - 1 行非零行，剩下的第 r ~ n - 1 行都是全零(这几行的每一列都是零),所以等式右边不可能为 !0
                return 2;//无解
        return 1; //有无穷多个解 
    }

    for (int i = n - 1; i >= 0; i --)//从下往上回代求解
        for (int j = i + 1; j < n; j ++)//a[j][n]表示求出的第 j 行 Xn 的值
            a[i][n] -= a[i][j] * a[j][n];
    
    return 0;//有唯一解
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n + 1; j ++)
            cin >> a[i][j];
    int t = gauss();
    if (t == 0)
    {
        for (int i = 0; i < n; i ++)
            printf("%.2lf\n", a[i][n]);
    }
    else if (t == 2)
    {
        cout << "No Solution" << '\n';
    }
    else 
        cout << "Infinite group solutions" << '\n';
    return 0;
}