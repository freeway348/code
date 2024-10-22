#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n,m;
int tr[5000010];
int a[5000010];

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
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) 
    {
        cin >> a[i];
        add(i, a[i] - a[i - 1]);
    }
    while(m --)
    {
        int x,y,z;
        cin >> x >> y >> z;
        add(x, z);
        add(y + 1, -z);
    }
    int min = 0x3f3f3f3f;
    for (int i = 1; i <= n; i ++)
    {
        int t = query(i);
        if (min > t) min = t;
        
    }
    cout << min;
    return 0;
}