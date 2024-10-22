#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5010;
int n;
int f[N];
int a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
    {
        f[i] = 1; // 先讨论从 f[1] 到 f[i] 的倒数第二个值不存在的情况，即：所有值都相同
        for (int j = 1; j < i; j ++) // 再从头讨论倒数第二个不相同的值为 f[j] 的情况
            if (a[i] > a[j])
                f[i] = max(f[i], f[j] + 1);
    }

    int res = 0;
    for (int i = 1; i <= n; i ++)
        res = max(res, f[i]);
    cout << res << endl;
    return 0;
}