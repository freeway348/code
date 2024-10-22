#include <iostream>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 100010;
int n,len;
pair<int,int> p[N],q[N];

bool check(int mid)
{
    int cnt = 0;
    for (int i = 0; i < n; i ++)
    {
        int L = p[i].first, S = p[i].second;
        if (S <= mid) 
        {
            int t = mid - S;
            int l = max(1, L - t);//如果区间左端点在1的左侧，则取1即可
            int r = min((ll)len, (ll)L + t);//如果区间右端点在len的右侧，则去len即可，否则就取该区间的右端点
            q[cnt ++] = {l,r};//将区间存入q数组中
        }
    }
    
    //区间合并
    sort(q, q + cnt);
    int st = -1, ed = -1;//存储上一个区间的左右端点
    for (int i = 0; i < cnt; i ++)
    {
        if (q[i].first <= ed + 1) ed = max(ed, q[i].second);//有交集则合并
        else 
        {
            st = q[i].first;
            ed = q[i].second;
        }
    }
    return st == 1 && ed == len;//判断总区间左端点是否为1，右端点是否为len
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> len;
    for (int i = 0;i < n;i ++)
        cin >> p[i].first >> p[i].second;//位于L[i]位置的管道会在S[i]时刻打开
    int l = 0, r = 2e9;
    while(l < r)//二分答案
    {
        int mid = (ll) l + r >> 1;//当l与r均取到2e9时会爆int，所以需要先将l + r的结果强制转化为longlong型
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l;
    return 0;
}