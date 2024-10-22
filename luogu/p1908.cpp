// 数据量大-------不开longlong见祖宗 
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

typedef long long LL;

const int N = 5e5 + 10;
int a[N],b[N];
int tr[N];
int n,bend;

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for (int i = x; i <= bend; i += lowbit(i))
        tr[i] += c;
}

LL query(int x)
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
        cin >> a[i];
    }
    // 离散化
    memcpy(b, a, sizeof a);

    sort(b + 1, b + n + 1);

    bend = unique(b + 1, b + n + 1) - (b + 1); // 不重复序列元素总数只有 end 个

    
    LL ans = 0;
    

    for (int i = 1; i <= n; i ++)
    {
        int x = lower_bound(b + 1, b + 1 + bend, a[i]) - b; // 找到 a[i] 离散化后在 b 中的下标
        ans += query(bend) - query(x); // 先加入的，并且值比 x 更小的，这不是逆序对，但剩下的加入树状数组的数就满足逆序对条件了
        add(x, 1); 

    }

    cout << ans << endl;
    return 0;
}