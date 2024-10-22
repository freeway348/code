// 1 <= n <= 20; 1 <= b <= a <= 1e18;   1 <= p <= 1e5
// �����õ�¬��˹����(lucas����)����Ԥ����
// ¬��˹����: C(b a) % p = C(b%p a%p) * C(b/p a/p)  ------------- ����C(b/p a/p)һֱ��lucas����ݹ����ã�ֱ�� a �� b ������ a < p && b < p
// ¬��˹���������������������ģ�ܴ󣬶�ģ����һ�������������ʱ�򣨼� a �� b �ܴ󣬵� p �Ǻ�С�������� C(b a) % p
// ʱ�临�Ӷ�ΪO(p * logp * logpN)----- logpN ------- log �� p Ϊ�׵� N
#include <iostream>

using namespace std;
typedef long long LL;

int p;

int qmi(int a, int b)
{
    int res = 1 % p;
    while(b)
    {
        if (b & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        b >>= 1;
    }
    return res;
}

int C(int a, int b)
{
    int res = 1;
    for (int i = 1, j = a; i <= b; i ++, j --)
    {
        res = (LL)res * j % p;
        res = (LL)res * qmi(i, p - 2) % p;
    }
    return res;
}

int lucas(LL a, LL b) // a > b
{
    if (a < p && b < p) return C(a,b);
    return (LL)C(a % p, b % p) * lucas(a / p, b / p) % p; //������� 1e5 ��˻ᱬ int
}

int main()
{
    int n;
    cin >> n;
    while(n --)
    {
        LL a,b;
        cin >> a >> b >> p;
        cout << lucas(a,b) << endl;
    }
    return 0;
}