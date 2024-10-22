#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1000010;
int n,k;
int h[N],w[N];
//查找能切出的正方体巧克力的最大边长，考虑二分
//判断答案是否在一个区间内产生，是否能判断条件成立缩小一半查找区间，不成立也缩小一半查找区间，满足条件就可以用二分
bool check(int mid)
{
    //因为h和w的数量级最高是1e5，而当巧克力的边长为1时，s(存储能切出几块巧克力)存储的数量级会达到1e5 * 1e5 = 1e10,会爆，所以需要定义为long long
    ll s = 0;
    for (int i = 0;i < n;i ++)
    {
        s += (w[i]/mid) * (h[i]/mid);
    }
    if (s >= k) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0;i < n;i ++)
        cin >> h[i] >> w[i];
    int l = 0,r = 1e5;
    //判断一块巧克力能切多少块边长为mid的正方形巧克力可以在用宽除以mid并向下取整（w[i]/mid）乘以用高除以mid并向下取整（h[i]/mid）
    //例如一块6×5的巧克力可以切成6((6/2)×(5/2))块2×2的巧克力
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l;
    return 0;
}