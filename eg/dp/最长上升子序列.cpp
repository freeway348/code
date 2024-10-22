// 原题：洛谷B3637
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5010;
int n;
int a[N],f[N]; // f[i] ------ 以第 i 个数结尾的最长上升序列

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++)
    {
        f[i] = 1; // 以 i 结尾的集合，初始时只有第 i 个数本身
        for (int j = 1; j < i; j ++)
            if (a[j] < a[i]) // 如果出现上升序列
                f[i] = max(f[i],f[j] + 1); // 取最大的上升序列
    }
    int res = 0;
    for (int i = 1; i <= n; i ++)
        res = max(res, f[i]);
    cout << res;
    return 0;
}