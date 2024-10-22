#include <iostream>
typedef long long LL;
using namespace std;
const int N = 1010;

int n,m;
int f[N];// 存取药剂总量为 N 时的最大经验值
int lo[N], w[N], v[N]; // 失败获得的经验值，成功获得的经验值，要消耗的药剂数量 

int main()
{
    cin >> n >> m; // n------好友数，m-----药剂数
    for (int i = 1; i <= n; i ++)
        cin >> lo[i] >> w[i] >> v[i];
    for (int i = 1; i <= n; i ++) // 遍历所有好友,分析情况
    // 由于遍历过程中，在对高药剂存量的情况进行分析时，其 f[j - v[i]] 不能在用到之前改变，所以必须从后往前遍历
        for (int j = m; j >= 0; j --) // 遍历所有药剂存量下的最大经验值
            if (j >= v[i])
                f[j] = max(f[j - v[i]] + w[i], f[j] + lo[i]);
            else f[j] += lo[i];
    cout << (LL)f[m]*5 ;
    return 0;
}