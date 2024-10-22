// acwing 1015
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 110;
int f[N][N];
int v[N][N];
int t;
int n,m;

int main()
{
    cin >> t;
    while(t --)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++)
                cin >> v[i][j];
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++)
                f[i][j] = max(f[i - 1][j] + v[i][j], f[i][j - 1] + v[i][j]);
        cout << f[n][m] << endl;
    }

    return 0;
}