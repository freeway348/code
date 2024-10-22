#include <iostream>
#include <cstring>
using namespace std;
const int N = 1000010;
int n,m;
int p[N];
long long b[N];
pair<int,pair<int,int>> q[N];

bool check(int mid)//二分查找第一个不满足条件的申请人
{
    memset(b,0,sizeof b);
    for (int i = 1;i <= mid;i ++)//查询从 1 到 mid 的订单是否满足条件
    {
        //差分
        b[q[i].second.first] += q[i].first;
        b[q[i].second.second + 1] -= q[i].first;
    }
    long long s = 0;
    for (int i = 1; i <= n;i ++)//遍历所有天数的教室数量
    {
        s += b[i];
        if (s > p[i]) return false;//需要的教室数量大于提供的教室数量，则返回false
    }
    return true;//满足条件
}

int main()
{
    cin >> n >> m;
    for (int i = 1 ; i <= n;i++)
    {
        cin >> p[i];
    }
    for(int j = 1;j <= m; j ++)
        cin >> q[j].first >> q[j].second.first >> q[j].second.second;
    
    int l = 0,r = m ;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;//满足条件则往后找
        else r = mid - 1;//不满足条件就往前找
    }
    if (r == m) cout << '0';//如果全部搜完都没有出错
    //l为最后一个满足条件的点
    else cout << "-1" << '\n' << l + 1;
    return 0;
}