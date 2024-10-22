//求 n 的最小质因数及其指数
#include <iostream>

using namespace std;

void divide(int n)
{
    for (int i = 2; i <= n / i; i ++)
    {
        if (n % i == 0)
        {
            int s = 0;
            while(n % i == 0)
            {
                s ++;
                n /= i;
            }
            cout << i << ' ' << s << '\n';
        }
    }
    if (n > 1) cout << n << ' ' << 1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while(n --)
    {
        int x;
        cin >> x;
        divide(x);
    }
    return 0;
}