//考虑逆序对
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e6 + 10;
int tr[N], h[N];//树状数组 tr 维护身高为 i 的人数
int ans[N];//存逆序对个数
int n;

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int k)
{
    for (int i = x; i <= N; i += lowbit(i)) tr[i] += k;
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
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> h[i];
        h[i] ++;//防止输入为 0 时存入树状数组出现错误
    }
    for (int i = 1; i <= n; i ++)
    {
        add(h[i],1);
        ans[i] += i - query(h[i]);//计算在 i 之前身高比 h[i] 更高的人数
    }
    memset(tr, 0, sizeof tr);
    for (int i = n; i >= 1; i --)
    {
        add(h[i],1);
        ans[i] += query(h[i] - 1);//计算在 i 之后身高比 h[i] 更矮的人数
    }
    long long sum = 0;
    for (int i = 1; i <= n; i ++)
    {
        sum += (long long)(ans[i] + 1) * ans[i] / 2;//计算心情值
    }
    cout << sum << '\n';
    return 0;
}