// a' == a/d, x' == x/d , m' == m/d
//得出结论 (a' + x') 与 m' 互质，所以gcd((a' + x'), m') = 1 ---------故可得 gcd((a' + x') % m', m') = 1
// 已知 0 <= x < m, 故 x' < m' , 所以 a' + x' 的数据范围是 a' ~ (a' + m' - 1),
// 所以 (a' + x') % m' 的范围在 0 ~ m' - 1
//故可推得： (a' + x') % m' 与 0 ~ m' - 1 同余(因为求(a' + x') % m'与 m' 互质的数的个数的结果与求 0 ~ m' - 1 中与m'互质的数个数结果相同)(因为(a' + x') % m'的区间范围就是 0 ~ m' - 1)
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;

LL gcd(LL a, LL b)
{
    return b ? gcd(b, a % b) : a;
}

LL phi(LL m)
{
    LL res = m;
    for (LL i = 2; i <= m / i; i ++)
    {
        if (m % i == 0)
        {
            while(m % i == 0)
                m /= i;
            res = res / i * ( i - 1 );
            //如果写成 res = res * ( i - 1 ) / i;
            //则在大数据时会出错
        }
        
    }
    if (m > 1) res = res / m * ( m - 1);
    return res;
}

int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        LL a,m;
        cin >> a >> m;
        LL d = gcd(a,m);
        a /= d, m /= d;
        cout << phi(m) << endl;
    }
    return 0;
}