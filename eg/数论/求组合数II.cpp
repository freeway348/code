// 取值： 1 <= n <= 100000(1e5) ;   1 <= b <= a <= 100000(1e5)
// 用逆元和阶乘预处理,时间复杂度为O(nlogn)
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
const int mod = 1e9 + 7;

int fact[N];//阶乘
int infact[N];//阶乘的逆元

int qmi(int a,int b,int p)//快速幂求 b^t 中间要 %m 防止爆掉
{
    int res = 1 % p;
    while(b)
    {
        if(b & 1) res = (long long)res * a % p;
        a = (long long)a * a % p;
        b >>= 1;
    }
    return res;
}

void init()//初始化阶乘及其逆元
{
    fact[0] = infact[0] = 1;
    for(int i = 1;i < N;i ++)
    {
        fact[i] = (long long)fact[i - 1] * i % mod;//求阶乘
        infact[i] = (long long)infact[i - 1] * qmi(i,mod - 2,mod) % mod;//快速幂求逆元
    }
}

int main()
{
    init();
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i ++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%lld\n",(long long)fact[a] * infact[b] % mod * infact[a - b] % mod);//C(n,m) = (n!) / [n! * (n - m)!]
        //因为除法不适用 a*b % p = (a % p) * (b % p) 这一规律，所以将除数转化为逆元后即可求解
    }
    return 0;
}
