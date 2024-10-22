// 数据量变为 1e5，数据范围在 -2e9 ~ 2e9 之间，所以之前的 O(n^2) 的朴素做法不可行，需要优化
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e5 + 10;
int a[N], q[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++)    cin >> a[i];
    int len = 0; // 最长上升子序列的长度
    q[0] = -2e9; // 处理边界问题
    for (int i = 0; i < n; i ++)
    {
        int l = 0, r = len;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            // 找到已知最长上升子序列中比 a[i] 小的、 最大的值
            if (q[mid] < a[i]) 
                l = mid;
            else r = mid - 1;
        }
        len = max(len, r + 1); // 把 a[i] 加到 q[r] 后边，二分查找后，若存在 q[r + 1]，必定比 a[i] 大，所以可以替换，而如果所有值都比 a[i] 小，那么就会将 a[i] 加到新的一位
        // 因为找上升子序列时：小的数肯定比大的数更好找上升序列，例如：1 3 4 比 1 3 6 更好找到接下来的上升序列
        q[r + 1] = a[i]; // 如果有，就替代，没有就添加
        
    }
    cout << len << endl;
    return 0;
}