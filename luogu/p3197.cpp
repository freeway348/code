#include <iostream>
using namespace std;

const int  mod = 100003;
typedef long long LL;

LL qpow(LL a, LL b)
{
    LL res = 1 % mod;
    while(b)
    {
        if (b & 1) res = (res * a) % mod;
        a = (a % mod) * (a % mod);
        b >>= 1;
    }
    return res;
}


int main()
{
    LL n,m;
    cin >> m >> n;
    LL t = (qpow(m,n) % mod - (m * qpow(m - 1, n - 1)) % mod) % mod;
    if (t < 0) t += mod; // 可能存在负数情况
    cout << t << '\n';
    return 0;
}