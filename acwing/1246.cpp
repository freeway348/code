#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int q[N],p[N];

int gcd(int a,int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> q[i];
    sort(q, q + n);
    int res = 0;
    for (int i = 0; i < n - 1; i ++)
        res = gcd(res, q[i + 1] - q[i]);
        //因为q数组中的数同属于一个等差数列，所以其差值一定是相同的，那么这些数之间两两相减的差值之间的 最大公约数一定是所要求的等差数列的差值d
    if (!res)
    {
        cout << n;
    }
    else 
    {
        int ans = (q[n - 1] - q[0]) / res + 1;
        cout << ans;
    }
    return 0;
}