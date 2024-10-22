#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 5e6 + 10;
int n, q;
int tr[N], tr2[N];
int a,b = 0x3f3f3f3f;

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        tr[i] = max(tr[i], c);
        tr2[i] = min(tr2[i], c);
    }
}

void query(int x, int y)
{
    for (int i = y; i >= x; i -= lowbit(i))
    {
        a = max(tr[i], a);
        b = min(tr2[i], b);
    }
    
}

int main()
{
    memset(tr2, 0x3f, sizeof tr2);
    cin >> n >> q;
    for (int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        add(i, x);
    }
    while(q --)
    {
        a = 0, b = 0x3f3f3f3f;
        int x,y;
        cin >> x >> y;
        query(x,y);
        int c = a - b;
        cout << a << ' ' << b << endl;
        cout << c << endl;
    }


    return 0;
}