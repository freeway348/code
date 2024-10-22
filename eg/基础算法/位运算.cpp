// ��Ŀ��
// ��Ӧ���⣺���P10446
/*
    �� a �� b mod p ��ֵ
    
    ���룺
    ��һ���������� a���ڶ����������� b���������������� p

    �����
    ���һ��������ʾ a^b % p ��ֵ

    ���ݷ�Χ:
    1 <= a,b,p <= 1e18

    ������
        ���룺
        3
        4
        5
        �����
        2
    
    ���������ٳ� -------- �üӷ���ʵ�ֳ˷�
    ����������Ŀ�������(�ó˷�ʵ�֣�ʱ�临�Ӷ�λO(1))������λ����˷��ܴ�������ݷ�Χ����,���ٶȸ�����ʱ�临�Ӷ�ΪO(logn)
*/
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

LL qadd(LL a, LL b, LL p)
{
    LL res = 0;
    while(b)
    {
        if (b & 1) res = (res + a) % p;
        a = (a + a) % p;
        b >>= 1; 
    }
    return res;
}

int main()
{
    LL a,b,p;
    cin >> a >> b >> p;
    cout << qadd(a,b,p);
    return 0;
}
