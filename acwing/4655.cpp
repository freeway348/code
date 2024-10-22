#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
int p[N],s[N];

int main()
{
    int n,m;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> p[i];
    cin >> m;
    for (int i = 1; i <= m; i ++)
    {
        int l, r;
        cin >> l >> r;
        //差分
        s[l] ++;
        s[r + 1] --;
    }
    for (int i = 1; i <= n; i ++)
        s[i] += s[i - 1];
    LL sum1 = 0,sum2 = 0;
    for (int i = 1; i <= n; i ++)
        sum1 += (LL) s[i] * p[i];
    sort(p + 1, p + n + 1);
    sort(s + 1, s + n + 1);
    for (int i = 1; i <= n; i ++)
        sum2 += (LL) s[i] * p[i];
    cout << sum2 - sum1;
    return 0;
}