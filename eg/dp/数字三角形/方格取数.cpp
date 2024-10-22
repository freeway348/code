// acwing 1027
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 11;
int f[N*2][N][N]; // f[k][i1][i1] : k = i1 + j1 = i2 + j2    i1 : 第一条路线所在的行； i2： 第二条路线所在的行
// 当 i1 + j1 == i2 + j2 时才可能有路线重合，即走过相同的步数后踩到同一格上
int w[N][N];

int main()
{
    int n;
    cin >> n;
    int a,b,c;
    while(cin >> a >> b >> c, a || b || c) // 如果不全输入 0， 就不停止输入
        w[a][b] = c;

    for (int k = 2; k <= n + n; k ++) // 从 (1,1) 开始走， 所以 k 的初值是 2 
        for (int i1 = 1; i1 <= n; i1 ++)
            for (int i2 = 1; i2 <= n; i2 ++)
            {
                int j1 = k - i1, j2 = k - i2; // 用 三个变量 k，i1，i2 来表示两个坐标，而不是用四维数组来表示，避免空间复杂度爆炸
                if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n) // 边界
                {
                    int t = w[i1][j1]; 
                    if (i1 != i2) // 如果路线重合，由于只能取一次，所以只取一个点，否则路线不重合，两个点都取
                        t += w[i2][j2];
                    int &x = f[k][i1][i2]; // 引用写法，更方便
                    // 四种路线选择状态
                    x = max(x, f[k - 1][i1 - 1][i2 - 1] + t); // 第一条路往 下 走， 第二条路也往 下 走
                    x = max(x, f[k - 1][i1 - 1][i2] + t); // 第一条路往 下 走， 第二条路往 右 走
                    x = max(x, f[k - 1][i1][i2 - 1] + t); // 第一条路往 右 走， 第二条路往 下 走
                    x = max(x, f[k - 1][i1][i2] + t); // 第一条路往 右 走， 第二条路也往 右 走
                }
            }
            
    cout << f[n + n][n][n] << endl;
    return 0;
}