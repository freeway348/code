#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 15010, M = 32010;
int ans[N],tr[M];//原数组和树状数组
int n;

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for (int i = x; i <= M; i += lowbit(i)) tr[i] += c;

}

int sum(int x)//计算从 1 到 x 的前缀和
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        int x,y;
        cin >> x >> y;
        //因为y增序排序，x在y相同时才增序排序,所以仅考虑x即可
        x ++;//树状数组下标必须从 1 开始，否则，当 x 为 0 时， 会出现死循环，即 i = x, i += lowbit(i) 始终为0
        add(x,1);
        ans[sum(x) - 1] ++;//因为先将 x 加入树状数组中，这颗星星本身不能算入，所以需要减 1
        //或者这段可以先 查询计算 1 - x 的前缀和，再加入到树状数组中
        // x ++;
        // ans[sun(x)] ++;
        // add(x, 1);
    }
    for (int i = 0; i < n; i ++) cout << ans[i] << '\n';
    return 0;
}