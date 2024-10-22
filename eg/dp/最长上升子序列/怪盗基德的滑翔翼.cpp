// 双向最长上升子序列

#include<iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int a[N];
int f[N];

int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        int res = 0;
        cin >> n;
        for (int i = 1; i <= n; i ++)
            cin >> a[i];

        // 正向求解LIS问题 ------ 从左往右找
        for (int i = 1; i <= n; i ++)
        {
            f[i] = 1;
            for (int j = 1; j < i; j ++)
                if (a[i] > a[j])
                    f[i] = max(f[i], f[j] + 1);
        }
        // 因为用的是同一个f数组存储数字，未防止反向求解时覆盖掉正向求解的结果，所以先进行一轮次res的max操作
        for (int i = 1; i <= n; i ++) 
            res = max(res, f[i]);
        
        // 反向求解LIS问题-------从右往左找
        for (int i = n; i; i --)
        {
            f[i] = 1;
            for (int j = n; j > i; j --)
                if (a[i] > a[j])
                    f[i] = max(f[i], f[j] + 1);
        }
        for (int i = 1; i <= n; i ++)
            res = max(res, f[i]);
        cout << res << endl;
    }
    
    return 0;
}