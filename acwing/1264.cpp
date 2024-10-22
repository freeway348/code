#include <iostream>

using namespace std;

const int N = 100010;
int n,m;
int tr[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int k)
{
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += k;
}

int query(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) 
        res += tr[i];
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        add(i,x);
    }
    while(m --)
    {
        int k;
        cin >> k;
        if (k == 0)
        {
            int a,b;
            cin >> a >> b;
            cout << query(b) - query(a - 1) << '\n';
        }
        else if (k == 1)
        {
            int a,b;
            cin >> a >> b;
            add(a, b);
        }
    }
    return 0;
}