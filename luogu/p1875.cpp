#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;
const int N = 1010, M = 1e6 + 10;
int q[N][N], w[N], ans[N];
LL res;
bool st[N]; // st[i] : 第 i 种药是否找到最低花费
int n;

int main()
{
    memset(q, -1, sizeof q);
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        cin >> w[i];
        ans[i] = 1;
    }
    int a,b,c;
    while(scanf("%d%d%d",&a, &b, &c) != EOF)
    {
        q[a][b] = c;
        q[b][a] = c; // a + b = c
    }
    for (int i = 0; i < n; i ++) // n 次循环，找到所有药的最小值
    {
        int vmin = 0x3f3f3f3f;
        for (int j = 0; j < n; j ++)
            if (!st[j] && w[j] < vmin) // 如果第 j 种药未找到最小花费,则找到花销最小的药
            {
                vmin = w[j];
                b = j;
            }
        st[b] = true;
        // 因为不存在 A + A = B 这种情况，所以前几次查找可能找不到最小花费的药剂，并且这两个最小花费的药剂还能合成第三种药
        // 换言之，下方的 for 循环中的 if (st-----) 判断的前置条件是： 已经找到了所有底层合剂（无法被其他药剂合成得到，只能购买获得）
        for (int j = 0; j < n; j ++) // 找到得到药 b 的最小花费
        {
            if (st[j] && q[b][j] != -1) // 在已知最小花费的药中选择,并且可以合成第三种药
            {
                if (w[q[b][j]] == w[b] + w[j])// 如果值相等，则多一些方案
                    ans[q[b][j]] += ans[b] * ans[j];
                else if (w[b] + w[j] < w[q[b][j]])
                {
                    ans[q[b][j]] = ans[b] * ans[j];
                    w[q[b][j]] = w[b] + w[j];
                }
            }
        }        
    }
    cout << w[0] << ' ' << ans[0];
    return 0;
}