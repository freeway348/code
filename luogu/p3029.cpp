#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

struct node
{
    int x,id;
    bool operator< (const node & M)const
    {
        if (x != M.x) return x < M.x;
        return id < M.id;
    } 
}a[N];

map<int,int> g;
int n;

int main()
{
    int sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i].x >> a[i].id;
        g[a[i].id] ++;
        if (g[a[i].id] == 1) sum ++;
    }
    g.clear();

    sort(a + 1, a + 1 + n);

    int len = 0x3f3f3f3f;
    int ans = 1;
    int r = 1;
    g[a[1].id] ++; // 要在循环外就将起始解决，否则进入循环会导致过程跟结果都出错
    for (int i = 1; i <= n; i ++) // 起点位置
    {
        while(ans < sum && r < n)
        {
            r ++;
            g[a[r].id] ++;
            if (g[a[r].id] == 1) ans ++;
        }
        if (ans == sum) len = min(len, a[r].x - a[i].x);
        g[a[i].id] --;
        if (g[a[i].id] == 0) ans --;
        
    }
    cout << len;
    return 0;
}