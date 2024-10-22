#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;

// long long 的数量级最大在 9e18

bool check(LL x)
{
    LL l = 1, r = 1e9;
    // 如果 r = x ，则当存在 2e5 个 1e9 数量级的方块，相加得到的数的数量级在 2e14, 假设第一次mid取到 l + r >> 1, 则 mid = 1e14, mid * mid = 1e28 > 2e14
    // 但是这导致了 mid 超过了 long long 的最大范围上限，所以数据溢出了
    while(l <= r)
    {
        LL mid = l + r >> 1;
        if (mid * mid == x) return true;
        if (mid * mid > x) r = mid - 1;
        else l = mid + 1; 
    }
    return false;
}

int main()
{
    // 防止数据量过大时TLE
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        cin >> n;
        LL s = 0;
        for (int i = 1; i <= n; i ++)
        {
            LL x;
            cin >> x;
            s += x;
        }
        if (check(s)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}