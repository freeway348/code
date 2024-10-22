//���� a �� b Ҫ����� C(b a) ģ 1e9 + 7 ��ֵ ---------- C(b a) = b! / ((b - a)! * a!)
//���ƹ�ʽ: C(b a) = C(b a-1) + C(b-1 a-1)
//ȡֵ�� 1 <= b <= a <= 2000(2e3);  1 <= n <=100000(1e5)
//�õ���,ʱ�临�Ӷ�ΪO(n^2)
#include <iostream>
using namespace std;

const int N = 2010, mod = 1e9 + 7;
int p[N][N];

void init()//������Ƿ�
{
    for (int i = 0; i < N; i ++)
        for (int j = 0; j <= i; j ++)
        {
            if (!j) p[i][j] = 1;//���C(b a)�У�b == 0������Ϊ 1�����C(b a)�� a Ϊ 0�� ����Ϊ 0
            else p[i][j] = (p[i - 1][j] + p[i - 1][j - 1]) % mod;//�ɵ��ƹ�ʽ��� C(j i) --------- i �����ѡ j ��������������������� j ���Ͳ������� j ��
         }
}

int main()
{
    init();
    int n;
    cin >> n;
    while(n --)
    {
        int a,b;
        cin >> a >> b;//��C(b a)
        cout << p[a][b] << '\n';
    }
    return 0;
}