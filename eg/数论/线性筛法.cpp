//�� 1 ~ n ����������
//����ɸ
#include <iostream>

using namespace std;

int primes[10000010], cnt;
bool st[10000010];

void is_primes(int n)
{
    for (int i = 2; i <= n; i ++)
    {
        if (!st[i]) primes[cnt ++] = i;//�洢�� cnt ������
        for (int j = 0; primes[j] * i <= n; j ++)//�����ǣ�prime[j] * i <= n,��ֻɸ 1 ~ n ��Χ�ڵ���
        {
            st[primes[j] * i] = true;//����prime[j]�洢�������������������������ĳ˻�ֻ�����Ǻ���������Ҫ�� st ������
            //��������ÿ�μ���ʱprime[j]������仯��ֻ�� i �ڵ��������Բ����ظ���ǣ������α��ͬһ���������˷�ʱ�䣩
            //���磬ֻ����prime[j] = 2, i = 3 ���������������� prime[j] = 3, i = 2 �����

            //primes[j]*i����С�����Ӿ���primes[j](��Ϊ prime[j] һ��С�� i , j ѭ������ i ѭ���ڣ����� j ֻ��ȡ�� 1 ~ i ������);

            if (i % primes[j] == 0) break;// primes[j] һ���� i ����С������(��Ϊ primes[j] һ�������������� primes[j] ��ֵ�Ǵ�С����洢��)
            //�� i % primes[j] == 0 ʱ��primes[j] һ���� i ����С������, Ҳһ���� primes[j] * i ����С������
            //�� i % primes[j] != 0 ʱ��primes[j] Ҳһ���� primes[j] * i ����С������
            //��������ֻ����С������ȥɸ������һ������ɸ���ظ��ĺ���
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