#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200010;
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
        res += tr[i];
    return res;
}


int main()
{
    cin >> n >> m;
    while(m --)
    {
        int a,b;
        cin >> a >> b;
        add(a, 1);
        add(b + 1, -1);
    }
    bool flag = false;
    int k,z;
    for (int i = 1; i <= n; i ++)
    {
        z = query(i);
        if (z > 1 || z == 0)
        {
            flag = true;
            k = i;
            break;
        }
    }
    if (flag) cout << k << ' ' << z;
    else cout << "OK";
    return 0;
}