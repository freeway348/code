#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
const int mod = 1e8 - 3;
LL ans;
int n;
int tr[N];
LL q[N];

struct node
{
    LL x;
    int y;
}a[N],b[N];

bool cmp(node h, node k)
{
    return h.x < k.x;
}

int lowbit(int x)
{
    return x & -x;
}

void add(int k, int c)
{
    for (int i = k; i <= n; i += lowbit(i))
        tr[i] += c;
}

LL query(LL x)
{
    LL res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i].x;
        a[i].y = i;
    }


    for (int i = 1; i <= n; i ++)
    {
        cin >> b[i].x;
        b[i].y = i;
    }

    sort(a + 1, a + n + 1, cmp);
    sort(b + 1, b + n + 1, cmp);


    // 不理解
    for (int i = 1; i <= n; i ++)
        q[a[i].y] = b[i].y;// q 中存储的是 b 数组离散化后的值在 a 中离散化后值的下标位置

    for (int i = n; i > 0; i --)
    {
        add(q[i],1);
        ans = (ans + query(q[i] - 1)) % mod;
    }
    
    cout << ans << '\n';
    return 0;
}