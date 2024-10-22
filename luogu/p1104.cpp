#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

struct node
{
    string x;
    int y; // 生日
    int z; // 输入顺序
    bool operator< (const node & M)const
    {
        if (y == M.y) return z > M.z; // 生日相同，则靠后输入的先输出
        return y < M.y; // 年龄从大到小,即：出生日期从小到大
    }
}p[100010];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        int a,b,c;
        string A;
        cin >> A >>  a >> b >> c;
        int t = c + b * 100 + a * 10000;
        p[i].x = A;
        p[i].y = t;
        p[i].z = i;
    }
    sort(p +  1, p + n + 1);
    for (int i = 1; i <= n; i ++)
        cout << p[i].x << endl;
    return 0;
}