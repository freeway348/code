#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;
int n,m;
int a[N];
int tr[N];

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
    int sum1 = 0, sum2 = 0;
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        add(a[i], 1);
        // ���Ƕ��� i ��ǰ����
        int x = query(i - 1); // �� a[i] С����
        int y = query(n) - query(i); // �� a[i] ��ĸ���
    }
    return 0;
}