#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;
const int N = 2e5 + 10;
int n;
int a[N];
int tr[N];

LL lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}

LL query(int x)
{
    LL res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main()
{
    LL sum1 = 0, sum2 = 0; // V 和 A 图腾
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        add(a[i], 1);
        LL lower, greater;
        // 因为是按照数的大小进行排序，所以query搜索也是
        lower = query(a[i] - 1); // 在 i 之前输入的，比 a[i] 小的数的个数
        greater = query(n) - query(a[i]); // 在 i 之前输入的，比 a[i] 大的数的个数
        sum1 += greater * (LL)(n - a[i] - greater); // 前边比 a[i] 大的数 * 后边比 a[i] 大的数
        // 因为所有数是 1 ~ n 的全排列，所以假设 a[i] = 3， 那么就有 1,2 这两个数比它小，总共有 n - 3 个数比它大
        sum2 += lower * (LL)(a[i] - 1 - lower);
    }

    cout << sum1 << ' ' << sum2 << endl;
    return 0;
}