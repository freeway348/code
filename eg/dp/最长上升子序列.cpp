// ԭ�⣺���B3637
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5010;
int n;
int a[N],f[N]; // f[i] ------ �Ե� i ������β�����������

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++)
    {
        f[i] = 1; // �� i ��β�ļ��ϣ���ʼʱֻ�е� i ��������
        for (int j = 1; j < i; j ++)
            if (a[j] < a[i]) // ���������������
                f[i] = max(f[i],f[j] + 1); // ȡ������������
    }
    int res = 0;
    for (int i = 1; i <= n; i ++)
        res = max(res, f[i]);
    cout << res;
    return 0;
}