// �ַ�����
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
            f[i][j] = max(f[i - 1][j], f[i][j - 1]); // ��Ϊ f[i - 1][j] �� f[i][j - 1] ��������״̬ f[i - 1][j - 1]�����ԾͲ���Ҫ�ٽ��бȽ�
            if (a[i] == b[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    cout << f[n][m];
    return 0;
}