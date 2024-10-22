#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e7 + 10;
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

long long query(int x)
{
    long long res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main()
{
    cin >> n >> m;
    while(m --)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            int a,b;
            cin >> a >> b;
            add(a, 1);
            add(b + 1, -1);
        }
        else if (x == 1)
        {
            int y;
            cin >> y;
            cout << query(y) << endl;
        }
    }


    return 0;
}