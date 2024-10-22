// 字符串型
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1010;

int f[N][N];
char a[N], b[N];
int n,m;

int main()
{
    cin >> n >> m;
    scanf("%s%s", a + 1, b + 1);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
        {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]); // 因为 f[i - 1][j] 和 f[i][j - 1] 都包含了状态 f[i - 1][j - 1]，所以就不需要再进行比较
            if (a[i] == b[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    cout << f[n][m];
    return 0;
}