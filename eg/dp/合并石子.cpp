// ����DP
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 310;
int f[N][N];
int s[N];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)   cin >> s[i];
    for (int i = 1; i <= n; i ++)   s[i] += s[i - 1];
    for (int len = 2; len <= n; len ++) // ���䳤��
        for (int i = 1; i + len - 1 <= n; i ++) // ����ͷ������β
        {
            int l = i, r = i + len - 1;
            f[l][r] = 1e8; // ��ΪҪȡ��С�����Բ�����Ĭ��0
            for (int k = l; k < r; k ++)
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
        }
    cout << f[1][n];
    return 0;
}