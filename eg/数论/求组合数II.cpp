// ȡֵ�� 1 <= n <= 100000(1e5) ;   1 <= b <= a <= 100000(1e5)
// ����Ԫ�ͽ׳�Ԥ����,ʱ�临�Ӷ�ΪO(nlogn)
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
const int mod = 1e9 + 7;

int fact[N];//�׳�
int infact[N];//�׳˵���Ԫ

int qmi(int a,int b,int p)//�������� b^t �м�Ҫ %m ��ֹ����
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

void init()//��ʼ���׳˼�����Ԫ
{
    fact[0] = infact[0] = 1;
    for(int i = 1;i < N;i ++)
    {
        fact[i] = (long long)fact[i - 1] * i % mod;//��׳�
        infact[i] = (long long)infact[i - 1] * qmi(i,mod - 2,mod) % mod;//����������Ԫ
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
        //��Ϊ���������� a*b % p = (a % p) * (b % p) ��һ���ɣ����Խ�����ת��Ϊ��Ԫ�󼴿����
    }
    return 0;
}
