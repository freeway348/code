#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const ll N = 1e6 + 10;
ll p[N];
int t,n;
bool st[N];



int main()
{
    cin >> t;
    while (t --)
    {
        int ans = 0;
        ll vmin = 0x3f3f3f3f;
        cin >> n;
        for (int i = 0;i < n ; i ++)
        {
            cin >> p[i];
            vmin = min(vmin,p[i]);
        }
        vmin += n;
        for (int i = 0; i < n;i ++)
        {
            if (p[i] < vmin)
                if (!st[vmin - p[i]])
                {
                    st[vmin - p[i]] = true;
                    ans ++ ;
                }
        }
        cout << ans << '\n';
    }
}