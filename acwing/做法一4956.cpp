//自己第一次想的做法
#include <iostream>
#include <utility>
using namespace std;
#define ll long long 
const int N = 1e6 + 10;
int n;
pair<int,int> p[N];
// 单调------>考虑二分
bool check(int mid)
{
    for (int i = 0;i <= n;i ++)
    {
        if (p[i].first/mid < p[i].second)
            return false;//说明mid太低或刚好满足
    }
    return true;// A/V > B
}

bool check1(int mid)
{
    for (int i = 0;i < n;i ++)
    {
        if (p[i].first/mid > p[i].second)//   A/V > B
            return false;//说明mid太高，V过小
    }
    return true;//说明   A/V <= B
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> p[i].first >> p[i].second;
   
    int tt = 1,rr = 1e9;//V的范围
    while (tt < rr)
    {
        int mid = tt + rr >> 1 ;
        if (check1(mid)) rr = mid;
        else tt = mid + 1;
    }
    cout << tt << ' ';
     int l = 1,r = 1e9;//转化率V的范围，是个正整数
    while (l < r)
    {
        int mid = l + r + 1 >> 1 ;//若l取0，则当r = 1时，mid = 0，出现了除以0的情况，会出现浮点溢出错误FPE
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l;
    return 0;
}