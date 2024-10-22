#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5e5 + 10;
int l[N], r[N];
char str[N];
//至少三头牛才能拍照，所以需要区分不同情况的区间
//第一种是：孤独的牛在区间中， 即 左边 与 右边各有至少一头其他品种的牛
//第二种情况是：孤独的牛在区间端点处，即只有左端点有 至少两头其他品种的牛，或者右端点...

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++)    cin >> str[i];
    for (int i = 0, sg = 0, sh = 0; i < n; i ++)//从前往后
        if (str[i] == 'G') l[i] = sh, sg ++, sh = 0;//记录在 G 之前有多少个连续的 H 
        else  l[i] = sg, sg = 0, sh ++;
    for (int i = n - 1, sg = 0, sh = 0; i >= 0; i --)//从后往前
        if (str[i] == 'G') r[i] = sh, sg ++, sh = 0;
        else  r[i] = sg, sg = 0, sh ++;
    long long res = 0;
    for (int i = 0; i < n; i ++)
        res += (long long) l[i] * r[i] + max(l[i] - 1, 0) + max(r[i] - 1, 0);
    cout << res;
    return 0;
}