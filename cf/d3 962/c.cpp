#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 2e5 + 10;
int a[N];
int b[N];
int c[N];
int n,q;

int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        
        cin >> n >> q;
        for (int i = 1; i <= n ; i++)
        {
            char x;
            cin >> x;
            a[i] = x - 'a' + 1; // 1 ~ 26
        }
        memcpy(c , a, sizeof a); // °Ñ b copy µ½ c ÖÐ
        sort(c + 1, c + 1 + n);
        int bend = unique(c + 1, c + 1 + n) - (c + 1);
        for (int i = 1; i <= n; i ++)
        {
            char x;
            cin >> x;
            int y = x - 'a' + 1;
            b[i] = lower_bound(c + 1, c + 1 + bend, y) - c;
        }
        for (int i = 1; i <= q; i ++)
        {
            int x,y;
            cin >> x >> y;
            
        }
    }
    return 0;
}