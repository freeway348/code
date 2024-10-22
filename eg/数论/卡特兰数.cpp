// 卡特兰数定义： H = C(n 2n) / (n + 1)
// 递推： C(n 2n) - C(n-1 2n)
#include <iostream>

using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;

int qmi(int a, int b, int p)
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

int main()
{
    int n;
    cin >> n;
    int a = 2*n, b = n;
    int res = 1;
    for (int i = a; i > a - b; i --) res = (LL)res * i % mod;
    for (int i = 1; i <= b; i ++) res = (LL)res * qmi(i, mod - 2, mod) % mod;

    res = res * (LL)qmi(n + 1, mod - 2, mod) % mod;

    cout << res << endl; 
    return 0;
}