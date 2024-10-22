//算法应用是前缀和，但在证明解释中有用到博弈论思路
#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e7 + 10;//因为给出数据是5*1e6,所以N不能比它小，不然就爆了，会出现segmentation fault错误
int p[N];

int main()
{
    int t,n;
    cin >> t;
    for (int j = 1;j <= t; j ++)
    {
        string A;
        cin >> n;
        cin >> A;
        for (int i = 1;i <= n; i ++)
            p[i] = p[i - 1] + A[i -  1] - '0';
        int m = (n + 1) / 2 ;
        int res = 0;
        for (int i = m; i <= n; i ++)
            res = max(res,p[i] - p[i - m]);
        cout << "Case #" << j << ": " <<  res << '\n';
    }
    return 0;
}