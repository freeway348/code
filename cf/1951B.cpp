#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int t;
int n,k;
const int N = 2e5 + 10;
int p[N];

int main()
{
    cin >> t;
    while (t --)
    {
        memset(p, 0, sizeof p);
        cin >> n >> k;
        for (int i = 1; i <= n; i ++)
            cin >> p[i];
        int pos = -1;
        for (int i = k - 1; i; i --)
            if (p[i] > p[k])
                pos = i;
        if (pos == -1)
        {
            int i;
            swap(p[1],p[k]);
            for (i = 2; i <= n; i ++)
                if (p[i] > p[1])
                    break;
            cout << i - 2 << endl;
        }
        else
        {
            int t = p[k];
            int ans = 0;
            swap(p[pos], p[k]);// 交换第一个比 k 大的值与 第 k 个值
            for (int i = pos - 1; i <= n; i ++)
            {
                if (p[i] == t)
                    continue;
                else if (p[i] > t)
                    break;
                if (i == 0)
                    continue;
                ans ++;
            }
            if (ans > pos - 2)
                cout << ans << endl;
            else 
                cout << pos - 2 << endl;
        }
        
    }
    return 0;
}