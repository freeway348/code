#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

const int N = 5e4 + 10;
int L,n,m;
int p[N];

bool check(int x)
{
    int hh = 0;
    int ans = 0; // 取走的石子数
    for (int i = 1; i <= n; i ++)
        if (x > p[i] - p[hh]) // 例如：原本每一步步伐为：2,2,4,1，当 x 取 3 时，第一次会将第一个 2 的石子拿掉，则值变为了 4，4, 1
            ans ++;
        else hh = i;
    return ans <= m;
}

int main()
{

    cin >> L >> n >> m;
    for (int i = 1; i <= n; i ++) // 起点是 0， 从起点到第一颗石子处是 p[1]
        cin >> p[i];
    p[++n] = L;
    // 考虑到直接计算距离比先计算每一步的间距更方便，所以我们这里不对原数组进行处理 
    int l = 1, r = L;
    while(l < r)
    {
        int mid = l + r + 1 >> 1; // 最短跳跃距离
        if (check(mid)) l = mid; // 如果得到最短距离的最大值 mid 需要的操作次数比 M 大，则说明 取多了,太大了，但仍是可行解，但我们要求的是可行解的最大值
        else r = mid - 1;
    }
    cout << l;
    return 0;
}