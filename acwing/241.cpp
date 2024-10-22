#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;
const int N = 2e5 + 10;
int n;
int a[N];
int tr[N];

LL lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}

LL query(int x)
{
    LL res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main()
{
    LL sum1 = 0, sum2 = 0; // V �� A ͼ��
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        add(a[i], 1);
        LL lower, greater;
        // ��Ϊ�ǰ������Ĵ�С������������query����Ҳ��
        lower = query(a[i] - 1); // �� i ֮ǰ����ģ��� a[i] С�����ĸ���
        greater = query(n) - query(a[i]); // �� i ֮ǰ����ģ��� a[i] ������ĸ���
        sum1 += greater * (LL)(n - a[i] - greater); // ǰ�߱� a[i] ����� * ��߱� a[i] �����
        // ��Ϊ�������� 1 ~ n ��ȫ���У����Լ��� a[i] = 3�� ��ô���� 1,2 ������������С���ܹ��� n - 3 ����������
        sum2 += lower * (LL)(a[i] - 1 - lower);
    }

    cout << sum1 << ' ' << sum2 << endl;
    return 0;
}