// acwing 100
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;
int f[N],a[N];


int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        f[i] = a[i] - a[i - 1];
    long long sum1 = 0, sum2 = 0;

    for (int i = 2; i <= n; i ++)
    {
        if (f[i] > 0) sum1 += f[i];
        else if (f[i] < 0) sum2 += f[i];
    }

    // 对差分数组的操作：
    /*
        f[i] += c, f[j + 1] -= c;
        方案：
        1.  2 <= i <= j <= n;
        2.  1 = i <= j <= n; ------------ 可以改变 f[1], 同时可以让差分数组的一个元素 - 1 （f[2] ~ f[n]）
        3.  2 <= i <= j = n + 1; ---------- 可以只让差分数组的一个元素 + 1 （f[[2] ~ f[n]）
        4.  i = 1, j = n + 1; --------- 对原数组所有元素均进行操作，换言之，就等同于未进行操作
    */
    cout << max(sum1, -sum2) << endl; // 即：min(sum1, -sum2) + abs(sum1 + sum2);
    cout << abs(sum1 + sum2) + 1 << endl; 
    // 第一种操作结束后，只剩下负数/正数，所以需要第 2 和第 3 中操作方案的组合使用，而使用第 2 种方案才会让 f[1] 的值改变，换言之，第二问问的是组合中的第 2 中操作有几种选法（选用几次）
    // 别忘记不使用第二种操作方案时的原数组
    return 0;
}