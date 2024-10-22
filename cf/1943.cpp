#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set> // 用于MEX运算

using namespace std;

int n;
int a[200010], f[200010];

int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        cin >> n;
        memset(a, 0, sizeof a);
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i ++)
        {
            cin >> a[i];
            f[a[i]] ++;
        }
        sort(a + 1, a + 1 + n); // 从小到大排序，然后 alice 和 bob 轮流取走最小的、仅存一个的数
        int t = 1;
        for (int i = 0; i <= 100010; i ++) // MEX 运算
        {
            if (f[i] == 0 || t == 2 && f[i] == 1)
            {
                cout << i << endl;
                break;
            }
            if (f[i] == 1 && t == 1)
                t ++;
        }
    }

    return 0;
}