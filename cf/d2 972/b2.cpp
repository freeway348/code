#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e5 + 10;
int t,n,m,q;
int a[N];

int main()
{
    cin >> t;
    while (t --)
    {
        cin >> n >> m >> q;
        for (int i = 1; i <= m; i ++)
            cin >> a[i];
        sort(a + 1, a + 1 + m);
        for (int i = 1; i <= q; i ++)
        {
            int x;
            cin >> x;
            if (x < a[1])
                cout << a[1] - 1 << endl;
            else if (x > a[m]) 
                cout << n - a[m] << endl; 
            else
            {
                int pos = lower_bound(a + 1, a + m + 1, x) - a - 1; // 找到第一个小于等于 x 的值的下标
                cout << (a[pos + 1] - a[pos]) / 2 << endl;
            }
        }
    }

    return 0;
}