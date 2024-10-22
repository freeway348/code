// 求二分图的最大匹配数量

/* 例题：

    题目：
给定一个二分图，其中左半部包含 n1 个点（编号为 1 ~ n1 ），右半部包含 n2 个点（编号 1 ~ n2），二分图共包含 m 条边。

数据保证任意一条边的两个端点都不可能在同一部分中。

请你求出二分图的最大匹配数。

二分图的匹配：给定一个二分图 G, 在 G 的一个子图 M 中， M 的边集 {E} 中的任意两条边都不依附于同一个顶点，则称 M 是一个匹配。

二分图的最大匹配：所有匹配中包含边数最多的一组匹配被称为二分图的最大匹配，其边数即为最大匹配数。 


    输入：
第一行包含三个整数 n1、n2 和 m
接下来 m 行，每行包含两个整数 u 和 v ,表示左半部点集中的点 u 和右半部点集中的点 v 之间存在一条边。

    输出：
输出一个整数，表示二分图的最大匹配数。

*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 100010;
int n1,n2,m;
int idx,e[M],h[N],ne[M];
int match[N]; // match[i] : 存储的是第 i 个人已匹配的对象
bool st[N]; // st[i] : 第 i 个人是否已匹配

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool find(int x) // 遍历 x （n1 数组中的人） 对应(能匹配)的所有人 （n2 中的所有人）
{
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j]) // 如果没被考虑过
        {
            st[j] = true;
            if (match[j] == 0 || find(match[j])) // 如果 n2 中第 j 个人未匹配，或者她匹配的对应 n1 中的人有其他选择
            {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin >> n1 >> n2 >> m;
    
    memset(h, -1, sizeof h);

    while(m --)
    {
        int a,b;
        cin >> a >> b;
        add(a,b);
    }

    int res = 0; // 匹配数
    for (int i = 1; i <= n1; i ++)
    {
        memset(st,false,sizeof st); // n2 数组中的人均只考虑一遍，是否考虑过用 st 数组来存
        if (find(i)) res ++; // 如果 n1 数组中第 i 个能找到其对应的 n2 ，则匹配数 + 1
    }
    cout << res << endl;
    return 0;
}