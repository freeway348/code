#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int n,m;
const int N = 5e5 + 10;
int tr[N];
int a[N];

struct node
{
    int x,y;
    int v;
    double xpos; // 落点
    int p = 1;
    int a;
}q[N];

bool cmp1(node Z, node M)
{
    if (Z.y != M.y)
            return Z.y < M.y;  // 先按纵坐标从小到大排序，再按终点横坐标从大到小排序
        return Z.xpos > M.xpos;
}

bool cmp2(node M, node T)
{
    return max(0, M.p - M.a) < max(0, T.p - T.a);
}

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}

int ask(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        cin >> q[i].x >> q[i].y >> q[i].v;
        q[i].xpos = (double)q[i].x + q[i].v * sqrt(2*q[i].y / 9.8);
    }

    for (int i = 1; i <= n; i ++)
        cin >> q[i].a;

    sort(q + 1, q + 1 + n, cmp1);

    for (int i = n; i; i --)
    {
        if (q[i].y != q[i + 1].y)
            memset(tr, 0, sizeof tr);
        q[i].p += ask(q[i].x);
        
        add(q[i].x, 1); // 已经将 y 相同的 xpos 按降序排序，所以只要看起始点的大小关系即可
    }

    sort(q + 1, q + 1 + n, cmp2);
    long long sum = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (m --)
        {
            sum += max(q[i].p - q[i].a, 0);
        }
        else 
            sum += q[i].p;
    }
    cout << sum << endl;
    return 0;
}