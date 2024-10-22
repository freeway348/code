#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
int tr[N]; //树状数组
int a[N], b[N]; // 离散数组
int d[11 * N], p[N]; // d ；区间起点， p ： 权值
int n;
int k;

struct node
{
    int v,z;
}q[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int y)
{
    for (int i = x; i <= k; i += lowbit(i))
        tr[i] += y;
}

int query(int x)
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
    {
        cin >> q[i].v >> q[i].z;
        a[i] = q[i].v, a[i + n] = q[i].z;
    }
    
    // 离散化
    sort(a + 1, a + 1 + 2 * n);
    int bend = unique(a + 1, a + 1 + 2 * n) - a - 1;

    // 进行二元组的预处理
    d[++ k] = a[1], p[k] = 1;
    for (int i = 2; i <= bend; i ++)
    {
        if (a[i] - a[i - 1] > 1) // 非连续,则切割区间
        {
            d[++ k] = a[i - 1] + 1;
            p[k] = a[i] - a[i - 1] - 1;
        }
        // 把要交换的点切割出来
        d[++ k] = a[i];
        p[k] = 1;
    }
    
    for (int i = 1; i <= k; i ++) b[i] = i;

    for (int i = 1; i <= n; i ++)
    {
        int x = lower_bound(d + 1, d + k + 1, q[i].v) - d; // 在 d 里边找需要交换的区间头
        int y = lower_bound(d + 1, d + k + 1, q[i].z) - d;
        swap(b[x],b[y]);
        swap(p[x],p[y]);
    }

    LL ans = 0;
    for (int i = k; i; i --)
    {
        ans += query(b[i] - 1) * (LL)p[i];
        add(b[i], p[i]); 
    }
    cout << ans << endl;
    return 0;
}