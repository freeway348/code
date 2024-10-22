#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n,m;

struct node
{
    int x; // ±¨ÃûºÅ
    int y; // ³É¼¨
    bool operator< (const node &M)
    {
        if (y != M.y) return y > M.y;
        else return x < M.x;
    }
}a[1000010];

int main()
{
    cin >> n >> m;
    m *= 1.5;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a + n);
    int k = 0;
    for (int i = 0; i < n; i ++)
        if (a[i].y >= a[m - 1].y)
            k ++;
    cout << a[m - 1].y << ' ' << k << endl;
    for (int i = 0; i < k; i ++)
        cout << a[i].x << ' ' << a[i].y << endl;
    return 0;
}