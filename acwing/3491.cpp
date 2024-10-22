#include <iostream>

using namespace std;
typedef long long LL;
int main()
{
    LL n;
    cin >> n;
    LL res = 1;
    for (int i = 2; i <= n / i; i ++)
    {
        if (n % i == 0)
        {
            int s = 0;
            while(n % i == 0)
                s ++,n /= i;
            if (s % 2 != 0) res *= i;
        }
    }
    if (n > 1) res *= n;
    cout << res << endl;
    return 0;
}