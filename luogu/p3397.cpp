// #include <iostream>
// #include <algorithm>
// #include <cstring>

// using namespace std;
// const int N = 1010;
// int a[N][N];
// int f[N][N];
// int n,m;

// int main()
// {  
//     cin >> n >> m;
//     for (int i = 1; i <= m; i ++)
//     {
//         int x1,y1,x2,y2;
//         cin >> x1 >> y1 >> x2 >> y2;
//         for (int j = y1; j <= y2; j ++)
//             for (int k = x1; k <= x2; k ++)
//             {
//                 f[k][j] += 1;
//             }
//     }
//     for (int i = 1; i <= n; i ++)
//     {
//         for (int j = 1; j <= n; j ++)
//             cout << f[i][j] << ' ';
//         cout << endl;
//     }
//     return 0;
// }

#include <iostream>
#include <algorithm>

using namespace std;
int n,m;
const int N = 1010;
int a[N][N], f[N][N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        f[x1][y1] += 1;
        f[x2 + 1][y2 + 1] += 1;
        f[x1][y2 + 1] -= 1;
        f[x2 + 1][y1] -= 1;
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
            cout << f[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}