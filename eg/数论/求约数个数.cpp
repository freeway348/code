//输入 n 个数，求这 n 个数的乘积的约数个数
//例如：输入一个数 N ,可将其分解为：N = p1^a1 * p2^a2 * …… * pk^ak,那么 N 的每个质因数的指数都可取 0 ~ a ,即总共有(a1 + 1) * (a2 + 1) * …… * (ak + 1)个约数 
//原理：先将输入的数（假设为 N) 分解质因数，记下其质因数和质因数的指数，最终将所有质因数的指数 + 1 再相乘即为约数个数
//排列组合知识点
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
    for (auto prime : primes) res = res * (prime.second + 1) % mod;
    cout << res << '\n';
    return 0;
}