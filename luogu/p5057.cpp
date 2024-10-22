#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
int tr[N];
int n,m;

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}

int query(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
    {
        res += tr[i];
        res %= 2;
    }
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i ++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int a,b;
            cin >> a >> b;
            add(a, 1);
            add(b + 1, -1);
        }
        else if (x == 2)
        {
            int y;
            cin >> y;
            cout << query(y) << endl;
        }
    }

    return 0;
}