#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];
int n,p;

bool check(double mid)
{
    double sum = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (a[i] * mid <= b[i]) // 原本的就够用了
            continue;
        sum += a[i] * mid - b[i];
    }
    return sum <= p * mid;
}

int main()
{   
    cin >> n >> p;
    double x = 0;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i] >> b[i];
        x += a[i];
    }
    if (x <= p)
    {
        cout << -1;
        return 0;
    }
    double l = 0, r = 1e10;
    while(r - l > 1e-4)
    {
        double mid = (l + r) / 2; // 最长使用时间
        if (check(mid)) l = mid;// 如果充电器可以支撑 mid 时间的电器使用
        else r = mid;
    }
    printf("%.6f", l);
    return 0;
}