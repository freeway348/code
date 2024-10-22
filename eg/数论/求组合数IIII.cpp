// ������ģ���㣬���� һ������ a �� b ��������,Ҫ��������ǵ������
// ��Χ�� 1 <= b <= a <= 5000;
// ���ݶ�������⣺ �ֽ������� = p1^a1 * p2^a2 * ���� * pk^ak
// ���磺��׳� b! �������� p �Ĵ����� b / p + b / (p^2) + b / (p^3) + ���� + b / (p^k);ֱ��p^k > b     (��Ϊ��ȡ��)
// ֤����b / p ��p, p^2, p^3......����������ȡ��һ����b / (p^2) �� p^2, p ^4 .......����������ȡ��һ��
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 5010;
int primes[N], cnt;
int sum[N];//��¼�����Ĵ���
bool st[N];

void get_primes(int n) //��� n �� 2 ~ n ��Χ������������
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

int get(int n, int p)//�õ� n �Ľ׳˵�����������
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
    
    for (int i = res.size() - 1; i >= 0; i --)//��Ϊ����߾��ȳ˷�ʱ�ǰ��������vector�����
        cout << res[i];
    cout << endl;

    return 0;
}