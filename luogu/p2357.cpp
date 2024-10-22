#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;

const int N = 2e5 + 10;
int n,m;
LL tr[N]; // 差分
LL tr2[N];
LL a[N];

LL lowbit(LL x)
{
    return x & -x;
}

void add(LL x, LL c)
{
    for (LL i = x; i <= n; i += lowbit(i))
        tr[i] += c, tr2[i] += x * c;
}

LL query(LL r)
{
    LL res = 0;
    for (LL i = r; i; i -= lowbit(i))
        res += tr[i] * (r + 1) - tr2[i];
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        add(i, a[i] - a[i - 1]);
    }
    int sum = 0;
    while(m --)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int j,k,l;
            cin >> j >> k >>l;
            add(j, l);
            add(k + 1, -l);
        }
        else if (x == 2) // 对于主墓碑的单一操作最好存在一个变量中，否则进行一次操作就要add两次，非常耗时
        {
            int j;
            cin >> j;
            sum += j;
        }
        else if (x == 3)
        {
            int j;
            cin >> j;
            sum -= j;
        }
        else if (x == 4)
        {
            int c,v;
            cin >> c >> v;
            LL t = 0;
            t = query(v) - query(c - 1);
            if (c == 1)
                cout << t + sum << endl;
            else cout << query(v) - query(c - 1) << endl;
        }
        else if (x == 5)
        {
            cout << sum + query(1) << endl;
        }
    }

    return 0;
}