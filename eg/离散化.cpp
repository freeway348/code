// 题目：假定有一个无限长的数轴，数轴上每个坐标上的数都是0。 (acwing 区间和)

// 现在，我们首先进行 n 次操作，每次操作将某一位置x上的数加c。

// 接下来，进行 m 次询问，每个询问包含两个整数l和r，你需要求出在区间[l, r]之间的所有数的和。

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
const int N = 3e5 + 10; // 题目规定范围在 1 ~ 1e5 之内，但是我们存的操作1 和操作 2 一共有 x，l，r 三个位置数，所以存储空间是三倍，具体情况具体分析
int n,m;
int s[N],a[N]; // s 数组存前缀和，a 数组存加数 c
typedef pair<int,int> PII;
vector<PII> adds,query;
vector<int> alls;

int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid; // 找到alls 中第一个比 x 大的数
        else l = mid + 1;
    }
    return r + 1; // 返回从 1 开始的连续自然数作为下标
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
    {
        int x,c;
        cin >> x >> c;
        adds.push_back({x,c});
        alls.push_back(x);
    }
    for (int i = 0; i < m; i ++)
    {
        int l,r;
        cin >> l >> r;
        query.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }
    // 去重
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    
    // 加
    for (auto item : adds)
    {
        int x = find(item.first); //求离散化后的值
        a[x] += item.second;
    }

    // 求前缀和
    for (int i = 1; i <= alls.size(); i ++) s[i] = s[i - 1] + a[i]; // 因为find 返回的是 1 ~ alls.size() 范围的下标，所以一共有 alls.size() 个

    // 询问
    for (auto item : query)
    {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}