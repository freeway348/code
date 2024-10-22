#include <iostream>
#include <cmath>
using namespace std;
const int N = 100;
int n,mid;
int p[N];
int cnt[51];
int res[51];
int k;
bool is_empty1(int q[])
{
    for (int i = 1; i <= 50; i ++)
        if (q[i] != 0) return false;
    return true;
}

void dfs(int x)
{
    if (k == x) return;
    for (int i = 1; i <= 50; i ++)
    {
        while (res[i] != 0 && res[x - i] != 0)
        {
            res[i]--;
            res[x - i]--;
        }
        if (! res[i])
        {
            dfs(x);
        }
    }
}

int main()
{
    cin >> n;
    while (n != 0)
    {
        for (int i = 0; i < n; i ++)
        {
            cin >> p[i];
            cnt[p[i]] ++;
        }
        int l = 1, r = 50;
        while ( l < r )
        {
            memcpy(res,cnt,sizeof cnt);//数组赋值copy
            mid = l + r + 1>> 1;
            if (!check(mid)) l = mid;
            else r = mid - 1;
        }
        cout << l << '\n';
        cin >> n;
    }
    return 0;
}