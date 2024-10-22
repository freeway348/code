#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10;

struct node
{
    int a,b,c,d;
}q[N];

int main()
{
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i ++)
        cin >> q[i].a >> q[i].b >> q[i].c >> q[i].d;
    
    int x,y;
    cin >> x >> y;
    bool flag = false;
    for (int i = n; i; i --)
    {
        if (x >= q[i].a && y >= q[i].b && x <= q[i].a + q[i].c && y <= q[i].b + q[i].d)
        {
            cout << i << endl;
            flag = true;
            break;
        }
    }
    if (!flag) cout << -1 << endl;
    return 0;
}