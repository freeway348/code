//给定一个数 n ，求 1 ~ n 中的每个数的欧拉函数之和

#include <iostream>

using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
int cnt,primes[N];
int phi[N]; 
bool st[N];

LL get_eulers(int n)
{
    phi[1] = 1;
    for (int i = 2; i <= n; i ++)
    {
        if (!st[i]) // 如果没被标记，则说明在之前的循环中未被筛选，说明 i 是质数
        {
            primes[cnt ++] = i;// 记录第cnt个质数
            phi[i] = i - 1;//  i 为质数，则从 1 ~ i 的与 i 互质的数就有 i - 1 个
        }
        for (int j = 0; primes[j] <= n / i; j ++)
        {
            st[primes[j] * i ] = true;//筛去每个质数的倍数
            if (i % primes[j] == 0)//如果已经筛过了就跳出循环
            {
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }
    LL res = 0;
    for (int i = 1; i <= n; i ++)
        res += phi[i];
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << get_eulers(n) << endl;
    return 0;
}