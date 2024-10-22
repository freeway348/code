#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int p[N],t[N];//p为理想温度，t为初始温度
int b[N],q[N];

int main()
{
    int n;
    cin >> n;
    int l = 0, r = n;
    for (int i = 1; i <= n; i ++)
        cin >> p[i];//结果 
    for (int i = 1; i <= n; i ++)//求差值
    {
        cin >> t[i];//初始
        q[i] = t[i] - p[i];//差值
    }
    for (int i = 1; i <= n + 1; i ++)//差分要操作到n + 1，因为要把先前的 某一个 加/减 操作 抵消
        b[i] = q[i] - q[i - 1];//求差值的差分
    ll res = 0;
    for (int i = 1;i <= n + 1; i ++)//差分要操作到n + 1
        if (b[i] > 0)
            res += b[i];//因为差分，所以正数和负数的总值相等，故正数总值即为操作次数
    cout << res;
    return 0;
}