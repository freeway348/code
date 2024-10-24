#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int n;
int f[N], g[N];
int a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    // ��ǰ���������������������� ------ ����LIS
    for (int i = 1; i <= n; i ++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j ++)
            if (a[i] > a[j])
                f[i] = max(f[i], f[j] + 1);
    }

    // �Ӻ���ǰ�������������� ------ ����LIS
    for (int i = n; i; i --)
    {
        g[i] = 1;
        for (int j = n; j > i; j --)
            if (a[i] > a[j])
                g[i] = max(g[i], g[j] + 1);
    }

    // ������ֵ
    int res = 0;
    for (int i = 1; i <= n; i ++)
        res = max(res, f[i] + g[i] - 1); // ��Ϊ�� a[i] Ϊ��ֵ��������LIS�ͷ���LIS���������о�������a[i]������㣬�ظ��ˣ�����Ҫ�� 1
    cout << n - res;
    
    return 0;
}