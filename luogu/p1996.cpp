// Ê÷×´Êý×é
#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;
int tr[N];
int n;

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
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        add(i, 1);
    int x = query(n);
    int k = 0;
    while(x)
    {
        k = k + m;

        x = query(n);
    }
    return 0;
}