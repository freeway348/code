#include <iostream>

using namespace std;
typedef long long LL;
const int mod = 10007;
LL qpow(int a,int b,int p)
{
    LL res = 1 % p;
    while(b)
    {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

LL mpow(int l, int r, int p)
{
    LL res = 1 % p;
    if (l == r)
    {
        res = res * l % p;
        return res;
    }
    else return mpow(l + 1, r, p);
}

int main()
{
    int a,b,k,n,m;
    cin >> a >> b >> k >> n >> m;
    cout << (LL)mpow(n + 1, k, mod) / mpow(1, m, mod) * qpow(a, n, mod) * qpow(b, m, mod) % mod << '\n';
    return 0;
}