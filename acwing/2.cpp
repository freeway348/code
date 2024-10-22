//一维数组优化
// #include <iostream>
// #include <algorithm>
// using namespace std;

// const int N = 1010;
// int f[N];
// int v[N], w[N];

// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     for (int i = 1; i <= n; i ++)
//         cin >> v[i] >> w[i];
//     for (int i = 1; i <= n; i ++)
//         for (int j = m; j >= v[i]; j --)
//             f[j] = max(f[j], f[j - v[i]] + w[i]);
//     cout << f[m] << endl;
//     return 0;
// }

//不优化
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int v[N], w[N];
int n,m;
int f[N][N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)   cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) 
            {
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);//选择更新后的f[i][j]（不含v[i]）还是包含v[i]的背包
            }
        }
    cout << f[n][m] << '\n';
    return 0;
}