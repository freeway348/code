// 定义一个 MEX 运算
// MEX运算：设 S 为一个非负整数集合，定义 MEX(S) 为求出不属于集合 S 的最小非负整数的运算, 例如：S = {1,2,3}，则 MEX(S) = 0
// SG函数：若点 x 是终点，则令 SG（x） = 0；若 x 不是终点，且 x 的下一步地点是 y1，y2 , …… , yn , 则 SG(x) = MEX{SG(y1),SG(y2),……,SG(yn)}
// 实现SG函数------用记忆化搜索
// 如果先手的 SG(x) = 0,则说明走不到终点，先手必败，若 SG(X) != 0, 则说明一定能走到终点，先手必胜

// 题目：给定 n 堆石子，两人每次可从这 n 堆石子中选一堆来拿取石子，但拿取的数量是限定的，必须是给出的数字集合 S 中的数字

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <cstring>
using namespace std;

const int N = 110, M = 10010;
int s[N],f[M];//s 数组--------数字集合； f 数组 ----------- sg函数值
int n,m;

int sg(int x)
{
    if (f[x] != -1) return f[x];
    unordered_set<int> S;
    for (int i = 0; i < m; i ++) // 求每一堆石子的sg函数
    {
        int sum = s[i];
        if (x >= sum) S.insert(sg(x - sum));//递归该堆石子的所有可能值的sg值
    }
    for (int i = 0; ; i ++)
        if (!S.count(i))//MEX运算找出 S 中没有的最小自然数
            return f[x] = i;// 把sg值赋给 f 数组并返回
}

int main()
{
    cin >> m;
    for(int i = 0; i < m; i ++)
        cin >> s[i];
    cin >> n;
    memset(f, -1, sizeof f);
    int res = 0;
    for (int i = 0; i < n; i ++)
    {
        int x;
        cin >> x;
        res ^= sg(x);//求该堆石子的sg函数
    }
    if (res) cout << "先手必胜" << endl;
    else cout << "先手必败" << endl;
    return 0;
}
