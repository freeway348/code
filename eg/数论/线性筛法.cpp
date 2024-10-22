//求 1 ~ n 的质数个数
//质数筛
#include <iostream>

using namespace std;

int primes[10000010], cnt;
bool st[10000010];

void is_primes(int n)
{
    for (int i = 2; i <= n; i ++)
    {
        if (!st[i]) primes[cnt ++] = i;//存储第 cnt 个质数
        for (int j = 0; primes[j] * i <= n; j ++)//条件是：prime[j] * i <= n,即只筛 1 ~ n 范围内的数
        {
            st[primes[j] * i] = true;//由于prime[j]存储的是质数，所以质数与整数的乘积只可能是合数，所以要用 st 数组标记
            //并且由于每次计算时prime[j]并不会变化，只有 i 在递增，所以不会重复标记（避免多次标记同一个合数而浪费时间）
            //例如，只可能prime[j] = 2, i = 3 的情况，而不会出现 prime[j] = 3, i = 2 的情况

            //primes[j]*i的最小质因子就是primes[j](因为 prime[j] 一定小于 i , j 循环是在 i 循环内，所以 j 只能取到 1 ~ i 的质数);

            if (i % primes[j] == 0) break;// primes[j] 一定是 i 的最小质因子(因为 primes[j] 一定是质数，并且 primes[j] 的值是从小到大存储的)
            //当 i % primes[j] == 0 时，primes[j] 一定是 i 的最小质因子, 也一定是 primes[j] * i 的最小质因子
            //当 i % primes[j] != 0 时，primes[j] 也一定是 primes[j] * i 的最小质因子
            //并且由于只用最小质因子去筛，所以一定不会筛到重复的合数
        }
    }
}

int main()
{
    int n;
    cin >> n;
    is_primes(n);
    cout << cnt << endl;
    return 0;
}