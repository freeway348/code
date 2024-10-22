// ����˼·������˼�� ----------- �������⣺���ţ��鲢���� 
// ������һ�������Ϊ���ɸ��ṹ��ͬ�������⣬ֱ���ݹ鵽һ����С�Ŀɵó����۵�������
// ��Ŀ: ����������Ȼ�� A �� B��S �� A^B ������Լ��֮�ͣ���� S mod 9901 ��ֵ
// ��Χ�� 0 <= A,B <= 5e7
/*
    ������
    ���룺2 3
    �����15
*/ 
#include <iostream>

using namespace std;

const int mod = 9901;

int qmi(int a, int b)
{
    int res = 1;
    a %= mod; // ���� a �ĳ�ʼֵ�󣬵��� a * a �� int
    while(b)
    {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// ����˼�������
int sum(int p, int k)
{
    // ����
    if (k == 1) return 1;
    // ż��
    if (k % 2 == 0) return (1 + qmi(p, k / 2)) * sum(p, k / 2) % mod;
    // ����
    return (sum(p, k - 1) + qmi(p, k - 1)) % mod;
}

int main()
{
    int a,b;
    cin >> a >> b;
    int res = 1;
    for (int i = 2; i <= a / i; i ++) // �� a �ֽ�������
    {
        if (a % i == 0)
        {
            int s = 0;
            while(a % i == 0)
            {
                s ++;
                a /= i;
            }
            res = res * sum(i, b * s + 1) % mod;
        }
    }
    if (a > 1) res = res * sum(a, b + 1) % mod;
    if (a == 0) res = 0;
    cout << res;
    return 0;
}