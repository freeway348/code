#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5010;
int n;
int f[N];
int a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
    {
        f[i] = 1; // �����۴� f[1] �� f[i] �ĵ����ڶ���ֵ�����ڵ��������������ֵ����ͬ
        for (int j = 1; j < i; j ++) // �ٴ�ͷ���۵����ڶ�������ͬ��ֵΪ f[j] �����
            if (a[i] > a[j])
                f[i] = max(f[i], f[j] + 1);
    }

    int res = 0;
    for (int i = 1; i <= n; i ++)
        res = max(res, f[i]);
    cout << res << endl;
    return 0;
}