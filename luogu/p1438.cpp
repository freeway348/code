#include <iostream>

using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
int n,m;
LL a[N];
LL b[N];
LL tr1[N], tr2[N];

LL lowbit(LL x)
{
    return x & -x;
}

void add(LL x, LL c)
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        tr1[i] += c;
        tr2[i] += c * x;
    }
}

LL query(LL x)
{
    LL res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += (x + 1) * tr1[i] - tr2[i];
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
        add(i, b[i] - b[i - 1]);
    }
    
    while(m --)
    {
        int opt;
        cin >> opt;
        if (opt == 1)
        {
            int l,r,k,d;
            cin >> l >> r >> k >> d;
            add(l, k);
            add(l + 1, -k + d);
            add(r + 1, - k - (r - l + 1) * d);
            add(r + 2, k + (r - l) * d);
        }
        else if (opt == 2)
        {
            LL p;
            cin >> p;
            cout << query(p) << endl;
        }
    }
    return 0;
}