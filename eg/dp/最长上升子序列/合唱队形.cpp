#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int n;
int f[N], g[N];
int a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    // 从前往后求解最长上升子序列问题 ------ 正向LIS
    for (int i = 1; i <= n; i ++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j ++)
            if (a[i] > a[j])
                f[i] = max(f[i], f[j] + 1);
    }

    // 从后往前求解最长上升子序列 ------ 反向LIS
    for (int i = n; i; i --)
    {
        g[i] = 1;
        for (int j = n; j > i; j --)
            if (a[i] > a[j])
                g[i] = max(g[i], g[j] + 1);
    }

    // 求解最大值
    int res = 0;
    for (int i = 1; i <= n; i ++)
        res = max(res, f[i] + g[i] - 1); // 因为以 a[i] 为峰值，且正向LIS和反向LIS的求解过程中均包含了a[i]这个景点，重复了，所以要减 1
    cout << n - res;
    
    return 0;
}