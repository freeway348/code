// 思路参考最长上升子序列的 nlogn 优化，结合离散化思路
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 2e5 + 10;
int n;
int a[N], b[N], q[N]; // q 数组存离散化后的 b 数组的最长上升子序列的值
int alls[N]; // alls[i]:存储值 i 在第一行中的位置 

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        alls[a[i]] = i;
    }
    for (int i = 0; i < n; i ++)
        cin >> b[i];

    int len = 0; // 最长上升子序列的长度

    for (int i = 0; i < n; i ++) // 遍历第二行(数组b)的所有值
    {
        int l = 0, r = len;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if (q[mid] < alls[b[i]]) // 找到数组 q 中的小于 alls[b[i]] 的最大下标值
                l = mid;
            else r = mid - 1;
        }
        len = max(len, r + 1);

        q[r + 1] = alls[b[i]];
    }
    cout << len << endl;
    return 0;
}