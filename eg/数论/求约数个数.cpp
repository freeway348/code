//���� n ���������� n �����ĳ˻���Լ������
//���磺����һ���� N ,�ɽ���ֽ�Ϊ��N = p1^a1 * p2^a2 * ���� * pk^ak,��ô N ��ÿ����������ָ������ȡ 0 ~ a ,���ܹ���(a1 + 1) * (a2 + 1) * ���� * (ak + 1)��Լ�� 
//ԭ���Ƚ��������������Ϊ N) �ֽ�������������������������������ָ�������ս�������������ָ�� + 1 ����˼�ΪԼ������
//�������֪ʶ��
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