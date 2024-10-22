// 不进行模运算，仅对 一对数字 a 和 b 进行运算,要求求出他们的组合数
// 范围： 1 <= b <= a <= 5000;
// 根据定义来求解： 分解质因数 = p1^a1 * p2^a2 * …… * pk^ak
// 例如：求阶乘 b! 的质因数 p 的次数： b / p + b / (p^2) + b / (p^3) + …… + b / (p^k);直至p^k > b     (均为下取整)
// 证明：b / p 将p, p^2, p^3......的质因数都取走一个，b / (p^2) 将 p^2, p ^4 .......的质因数再取走一个
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 5010;
int primes[N], cnt;
int sum[N];//记录质数的次数
bool st[N];

void get_primes(int n) //标记 n 的 2 ~ n 范围的所有质因数
{
    for (int i = 2; i <= n; i ++)
    {
        if (!st[i]) primes[cnt ++] = i;
        for (int j = 0; primes[j] <= n / i; j ++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int get(int n, int p)//得到 n 的阶乘的质因数个数
{
    int res = 0;
    while(n)
    {
        res += n / p;
        n /= p;
    }
    return res;
}

vector<int> mul(vector<int> a, int b)
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i ++)
    {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while(t)
    {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}

int main()
{
    int a,b;
    cin >> a >> b;

    get_primes(a);
    
    for (int i = 0; i < cnt; i ++)
    {
        int p = primes[i];
        sum[i] = get(a, p) - get(b, p) - get(a - b, p);
    }

    vector<int> res;
    res.push_back(1);

    for (int i = 0; i < cnt; i ++)
        for (int j = 0; j < sum[i]; j ++)
            res = mul(res, primes[i]);
    
    for (int i = res.size() - 1; i >= 0; i --)//因为计算高精度乘法时是按逆序存入vector数组的
        cout << res[i];
    cout << endl;

    return 0;
}