// acwing 100
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;
int f[N],a[N];


int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        f[i] = a[i] - a[i - 1];
    long long sum1 = 0, sum2 = 0;

    for (int i = 2; i <= n; i ++)
    {
        if (f[i] > 0) sum1 += f[i];
        else if (f[i] < 0) sum2 += f[i];
    }

    // �Բ������Ĳ�����
    /*
        f[i] += c, f[j + 1] -= c;
        ������
        1.  2 <= i <= j <= n;
        2.  1 = i <= j <= n; ------------ ���Ըı� f[1], ͬʱ�����ò�������һ��Ԫ�� - 1 ��f[2] ~ f[n]��
        3.  2 <= i <= j = n + 1; ---------- ����ֻ�ò�������һ��Ԫ�� + 1 ��f[[2] ~ f[n]��
        4.  i = 1, j = n + 1; --------- ��ԭ��������Ԫ�ؾ����в���������֮���͵�ͬ��δ���в���
    */
    cout << max(sum1, -sum2) << endl; // ����min(sum1, -sum2) + abs(sum1 + sum2);
    cout << abs(sum1 + sum2) + 1 << endl; 
    // ��һ�ֲ���������ֻʣ�¸���/������������Ҫ�� 2 �͵� 3 �в������������ʹ�ã���ʹ�õ� 2 �ַ����Ż��� f[1] ��ֵ�ı䣬����֮���ڶ����ʵ�������еĵ� 2 �в����м���ѡ����ѡ�ü��Σ�
    // �����ǲ�ʹ�õڶ��ֲ�������ʱ��ԭ����
    return 0;
}