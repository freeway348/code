#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 110;
int tr[N];
int t, n;
int a[N], b[N];

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
    cin >> t;
    while(t --)
    {
        memset(tr, 0, sizeof tr);
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);

        cin >> n;
        for (int i = 1; i <= n; i ++)
            cin >> a[i];

        // 离散化
        memcpy(b, a, sizeof a);
        sort(b + 1, b + n + 1);
        int bend = unique(b + 1, b + n + 1) - b - 1;

        int ans = 0;
        for (int i = n; i; i --)
        {
            int x = lower_bound(b + 1, b + bend + 1, a[i]) - b; // a[i] 在 b 数组中的次序
            ans += query(x);
            add(x,1);
        }
        cout << "Optimal train swapping takes " << ans << " swaps." << endl;
    }
    return 0;
}