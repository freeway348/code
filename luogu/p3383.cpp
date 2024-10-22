#include <iostream>

using namespace std;
typedef long long LL;
const int N = 1e8 + 10;
int cnt,primes[N];
bool st[N];
int n;

void init()
{
    for (int i = 2; i <= n; i ++)
    {
        if (!st[i])
        {
            primes[cnt ++] = i;
        }
        for (int j = 0; primes[j] <= n / i; j ++)
        {
            st[primes[j] * i ] = true;
            if (i % primes[j] == 0)
            {
                break;
            }
        }
    }
}

int main()
{
    int q;
    cin >> n >> q;
    init();
    while(q --)
    {
        int x;
        cin >> x;
        cout << primes[x - 1] << endl;
    }
    return 0;
}