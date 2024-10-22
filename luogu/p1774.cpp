#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 500010;
int a[N];
int n;
int b[N];
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
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
        ans += tr[i];
    return ans;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    memcpy(b, a, sizeof a);
    sort(b + 1, b + n + 1);
    int bend = unique(b + 1, b + n + 1) - (b + 1);
    long long res = 0; // 必须要开 long long， 不然大数据量计算就会报错
    for (int i = 1; i <= n; i ++)
    {
        int x = lower_bound(b + 1, b + 1 + bend, a[i]) - b; // 因为下标要从 1 开始，所以 - b， 而不是 - (b + 1)
        res += query(bend) - query(x);
        add(x, 1);
    }
    cout << res << endl;
    return 0;
}