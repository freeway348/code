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
        // ��С����sort����,Ҫ��������������磺32��321�������Ϊ 32321 > 32132�����ֻ�Ǽ򵥵���λ�жϴ�С
        // ������ "321" > "32" ������������ַ�����ϱ�� 32132�������Ǵ����
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