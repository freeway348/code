#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e6 + 10;
typedef long long LL;


int main()
{
    double n,m,k;
    cin >> n >> m >> k;
    double l = 0, r = 400;    
    while(r - l > 1e-4) // 精度要求
    {
        double w = n;
        double mid = (l + r) / 2;
        for (int i = 1; i <= k; i ++)
        {
            w = w - m + w * (mid / 100);
        }
        if (w > 1e-4) // 没还清
            r = mid;
        else
            l = mid;
    }
    printf("%.1f", l);
    return 0;
}