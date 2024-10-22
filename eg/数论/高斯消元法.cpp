//����O(n^3)��ʱ�临�Ӷ������ n ������ʽ������
//�Ƚ��� n ���������ÿ���ݼ�������ϵ���͵Ⱥ��ұߵĽ�����һ������ϵ�������볣��������ɵ��������
//���ֵȼ۱任(�������б任)��
//��1����ĳһ�г�һ���������
//��2������ĳ����
//��3����ĳ�е����ɱ��ӵ���һ��
//��˹��Ԫ: �Ƚ�ϵ���������������Ǿ����ٴ��µ��ϻش����(�õ����������ֻ�����еĳ�������ֻ��ϵ������任�����������任)
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
const double eps = 1e-6;//�������ó�int�ͣ������ж��Ƿ�С������ 0 ʱ���޷��жϣ���Ϊint�ͻὫ����������Ϊ 0 �������� 1e-6

const int N = 110;
double a[N][N];
int n;

int gauss()//�������Ϊ�������κ��ٴ������ϻش����
{
    int r,c;
    for (c = 0, r = 0; c < n; c ++)// r ��ʾǰ r - 1 �о�����ɱ任��������ѡ��� r �н��б任, c ��ʾ�� c ��
    {
        int t = r;
        for (int i = r + 1; i < n; i ++)//�ڵ� c ����ѡ�����������ڵ��У����任���� r ��
            if (fabs(a[i][c]) > fabs(a[t][c]))//�󸡵����ľ���ֵ
                t = i;

        if (fabs(a[t][c]) < eps)//����� c �����µ� (r ~ (n - 1) �о�Ϊ 0 ������������
            continue;

        for (int i = c; i <= n; i ++) swap(a[r][i],a[t][i]);//���� r ����� t ��(����������)����
        for (int i = n; i >= c; i --) a[r][i] /= a[r][c];//���� r �еĵ� c ������Ϊ 1 (��Ԫ)
        for (int i = r + 1; i < n; i ++)//���� (r + 1) ~ (n - 1) �е� c �о���Ϊ 0
            if (fabs(a[i][c]) > eps)//�����Ϊ 0 ����в�����Ϊ 0 �򲻽��в���
            {
                for (int j = n; j >= c; j --)
                //��Ϊ���� i �е� c �е�����Ϊ 0 �Ĳ������ǣ�a[i][c] -= a[i][c] * a[r][c]
                    a[i][j] -= a[r][j] * a[i][c];// ���Խ��� i �е� j �е�����Ϊ 0 �Ĳ������ǣ�a[i][j] -= a[i][c] * a[r][j]
            }

        r ++;
    }
    if (r < n) //��һ�е���ԪΪ 0
    {
        for (int i = r; i < n; i ++)
            if (fabs(a[i][n]) > eps)//ֻ���� r - 1 �з����У�ʣ�µĵ� r ~ n - 1 �ж���ȫ��(�⼸�е�ÿһ�ж�����),���Ե�ʽ�ұ߲�����Ϊ !0
                return 2;//�޽�
        return 1; //���������� 
    }

    for (int i = n - 1; i >= 0; i --)//�������ϻش����
        for (int j = i + 1; j < n; j ++)//a[j][n]��ʾ����ĵ� j �� Xn ��ֵ
            a[i][n] -= a[i][j] * a[j][n];
    
    return 0;//��Ψһ��
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n + 1; j ++)
            cin >> a[i][j];
    int t = gauss();
    if (t == 0)
    {
        for (int i = 0; i < n; i ++)
            printf("%.2lf\n", a[i][n]);
    }
    else if (t == 2)
    {
        cout << "No Solution" << '\n';
    }
    else 
        cout << "Infinite group solutions" << '\n';
    return 0;
}