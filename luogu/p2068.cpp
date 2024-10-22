#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n,w;
long long tr[100010];


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
    cin >> n >> w;
    while(w --)
    {
        char op[2];
        scanf("%s",op);
        if (op[0] == 'x')
        {
            int a,b;
            cin >> a >> b;
            add(a, b);
        }
        else if (op[0] == 'y')
        {
            int a,b;
            cin >> a >> b;
            cout << query(b) - query(a - 1) << endl;
        }
    }
    return 0;
}