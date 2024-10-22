//ʱ�临�Ӷ�ΪO(logn)
//��չŷ������㷨������һ��a,b��Ҫ�����һ�Է������� x��y ʹ�� a*x + b*y = d = N * gcd(a,b),����x,y����ȡ������Сֵ(��Ϊ a*x + b*y = n*gcd(a,b) )
//��Ϊ�� a*x + b*y != N * gcd(a,b)ʱ��һ���޽�
//������ 0 �����Լ�����������������
//���������֪������a,b��һ�����ڷ������� x��y ʹ�� a*x + b*y = gcd(a,b),����x,y����ȡ������Сֵ(��Ϊ a*x + b*y = n*gcd(a,b) )
// a*x + b*y = gcd(a,b) = gcd(b, a % b), �� b*y + x*(a - (a / b)��ȡ�� * b) = gcd(b, a % b) = gcd(a,b)
//�ɵã� a*x + b*(y - a / b * x) = gcd(a,b)
// a*x + b*y = d ������ͨ��Ϊ��x = x0 - b / d * k;  y = y0 + b / d * k      (kȡ����)
//ͨ����ʽ�� a * (x - b / d) + b * (y + a / d) = d  �Ƶ�     (�˷�����һ�¼��ɽ������ڵļ����ͼ���������)
#include <iostream>

using namespace std;

int exgcd(int a,int b,int &x,int &y)//���յõ��� x ��Ϊ a ģ b �ĳ˷���Ԫ
{
    if (!b)//����� a % 0,��ɵó���a*1 + 0*y == a
    {
        x = 1,y = 0;
        return a;
    }
    int d = exgcd(b,a % b,y,x);
    y -= a / b * x;
    return d;
}

int main()
{
    int n;
    cin >> n;
    while(n --)
    {
        int a,b,x,y;
        cin >> a >> b;
        exgcd(a,b,x,y);
        cout << x << ' ' << y << endl;
    }
    return 0;
}