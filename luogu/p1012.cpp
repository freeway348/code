#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;
char p[110][110];

struct node
{
   string x;
   int y;
   bool operator< (const node & M)const
   {
        return (x + M.x) > (M.x + x);   
        // 从小到大sort排序,要特判特殊情况，如：32和321，其组合为 32321 > 32132，如果只是简单地逐位判断大小
        // 则会出现 "321" > "32" 的情况而导致字符串组合变成 32132，但这是错误的
   }
}a[10010];

int main()
{   
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        cin >> p[i];
        a[i].x = p[i];
        a[i].y = i;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i ++)
        cout << p[a[i].y];
    return 0;
}