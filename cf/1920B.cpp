// ��Ϊ alice ��Ҫ�������֮�ͣ����ǣ�bob ��Ҫ��С������֮�ͣ�����bobһ���Ὣ������ǰ x �����ֵȡ������ailice ��Ҫ�������������֮�ͣ���Ҫ����������ʧ��������Ҫ��ǰ k �����ֵȥ����������ʧ���ܼ���һ������
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        int n,k,x;
        int a[200010] = {0};
        cin >> n >> k >> x;
        for (int i = 1; i <= n; i ++)
            cin >> a[i];

        sort(a + 1, a + n + 1, greater<int>() ); // �Ӵ�С
        
        for (int i = 1; i <= n; i ++)
            a[i] += a[i - 1]; // ����ǰ׺��
        
        int vmax = - 1e9;

        for (int i = 0; i <= k; i ++) // ���� alice ɾ�� i ��Ԫ�أ������ֵ 
        {
            int b;
            if (i + x > n)
                b = a[n] - a[i];
            else 
                b = a[i + x] - a[i];
            vmax = max(vmax, a[n] - a[i] - 2 * b);
        }

        cout << vmax << '\n';
    }
}