#include <iostream>
#include <algorithm>
using namespace std;

int n,m,x,y;

bool check(int h)
{
    int a = h / y - h / x / y;//只能给牛A的
    int b = h / x - h / x / y;//只能给牛B的
    int c = h - h / x - h / y + h / x / y; // 不独属于任何牛的楼层（两头牛都能分）
    //因为 h / x 和 h / y 都包含了 h / x / y 所以要再加上一个
    int s1 = max(0, n - a), s2 = max(0, m - b);//剩下的需求楼层
    return s1 + s2 <= c;//判断是否能满足
}

int main()
{
    cin >> n >> m >> x >> y;
    int l = 1, r = 2e9;
    while(l < r)
    {
        int mid = (long long)l + r >> 1;
        //考虑极端状况，若 l = r 并且都在1e9数量级，则可能会在计算和的时候爆int，所以要强制类型转换，或者直接将l和r都设为long long型
        if (check(mid)) r = mid;//如果满足条件，则说明可能楼盖高了
        else l = mid + 1;
    }   
    cout << r << '\n';
    return 0;
}