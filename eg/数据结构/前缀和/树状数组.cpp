//Âå¹ÈP3374
#include <iostream>

using namespace std;

const int N = 5e5 + 10;
int tr[N];
int n,m;

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
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
        int x;
        cin >> x;
        if (x == 1)
        {
            int a,b;
            cin >> a >> b;
            add(a,b);
        }
        else if (x == 2)
        {
            int ans = 0, a, b;
            cin >> a >> b;
            ans = query(b) - query(a - 1);
            cout << ans << '\n';
        }
    }
    return 0;
}