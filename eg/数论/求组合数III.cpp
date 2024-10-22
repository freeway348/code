// 1 <= n <= 20; 1 <= b <= a <= 1e18;   1 <= p <= 1e5
// 这里用到卢卡斯定理(lucas定理)进行预处理
// 卢卡斯定理: C(b a) % p = C(b%p a%p) * C(b/p a/p)  ------------- 其中C(b/p a/p)一直用lucas定理递归套用，直至 a 和 b 均满足 a < p && b < p
// 卢卡斯定理适用条件：当问题规模很大，而模数是一个不大的质数的时候（即 a 和 b 很大，但 p 是很小的素数） C(b a) % p
// 时间复杂度为O(p * logp * logpN)----- logpN ------- log 以 p 为底的 N
#include <iostream>

using namespace std;
typedef long long LL;

int p;

int qmi(int a, int b)
{
    int res = 1 % p;
    while(b)
    {
        if (b & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        b >>= 1;
    }
    return res;
}

int C(int a, int b)
{
    int res = 1;
    for (int i = 1, j = a; i <= b; i ++, j --)
    {
        res = (LL)res * j % p;
        res = (LL)res * qmi(i, p - 2) % p;
    }
    return res;
}

int lucas(LL a, LL b) // a > b
{
    if (a < p && b < p) return C(a,b);
    return (LL)C(a % p, b % p) * lucas(a / p, b / p) % p; //如果两个 1e5 相乘会爆 int
}

int main()
{
    int n;
    cin >> n;
    while(n --)
    {
        LL a,b;
        cin >> a >> b >> p;
        cout << lucas(a,b) << endl;
    }
    return 0;
}