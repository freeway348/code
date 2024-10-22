#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    unordered_map<int,int> primes;
    while(n --)
    {
        int x;
        cin >> x;
        for (int i = 2; i <= x / i; i ++)
        {
            if (x % i == 0) 
                while(x % i == 0)
                    x /= i, primes[i] ++;
        }
        if (x > 1) primes[x] ++;
    }
    LL res = 1;
    for (auto prime : primes) 
    {
        int p = prime.first, a = prime.second;//p是底数，a是指数
        LL t = 1;
        //经过while循环后最终能得到 p^a + p^(a - 1) + …… + 1
        while(a --)
        {
            t = (t * p + 1) % mod;
        }
        res = res * t % mod;
    }
    cout << res << '\n';
    return 0;
}