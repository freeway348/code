#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
const int N = 1e3 + 10, INF = -0x3f3f3f3f;
int a[N][N];
int f[N][N];

int main()
{
	cin >> n;
    memset(f, INF,sizeof f);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= i; j ++)
            cin >> a[i][j];
    f[1][1] = a[1][1];
    for (int i = 2; i <= n; i ++)
        for (int j = 1; j <= i; j ++)
            f[i][j] = max(f[i - 1][j],f[i - 1][j - 1]) + a[i][j];
    int ans = INF;
    for (int i = 1; i <= n; i ++)
        ans = max(ans, f[n][i]);
    cout << ans;
    return 0;
}