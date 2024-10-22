#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
LL tr[N];
int n;
LL a[N],b[N];

LL lowbit(LL x)
{
    return x & -x;
}

void add(LL x, LL c)
{
    for (int i = x; i <= n; i += lowbit(i))
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
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    memcpy(b,a,sizeof a);
    sort(b + 1, b + n + 1);
    LL bend = unique(b + 1, b + n + 1) - (b + 1);
    LL ans = 0;
    for (int i = 1; i <= n; i ++) // 第 i 个数
    {
        int x = lower_bound(b + 1, b + bend + 1, a[i]) - b;
        ans = max(ans, i - query(x)); // query(x) : 在 x 之前有几个比 x 小的、并且在 x 之前就加入的------非逆序对，再考虑是否有相同的值，所以用 i - query(x) 代表最终答案
        add(x,1);
    }
    cout << ans << endl;
    return 0;
}