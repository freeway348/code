// 区间DP
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
    for (int len = 2; len <= n; len ++) // 区间长度
        for (int i = 1; i + len - 1 <= n; i ++) // 区间头和区间尾
        {
            int l = i, r = i + len - 1;
            f[l][r] = 1e8; // 因为要取最小，所以不能用默认0
            for (int k = l; k < r; k ++)
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
        }
    cout << f[1][n];
    return 0;
}