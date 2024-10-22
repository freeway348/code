// ˫�������������

#include<iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int a[N];
int f[N];

int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        int res = 0;
        cin >> n;
        for (int i = 1; i <= n; i ++)
            cin >> a[i];

        // �������LIS���� ------ ����������
        for (int i = 1; i <= n; i ++)
        {
            f[i] = 1;
            for (int j = 1; j < i; j ++)
                if (a[i] > a[j])
                    f[i] = max(f[i], f[j] + 1);
        }
        // ��Ϊ�õ���ͬһ��f����洢���֣�δ��ֹ�������ʱ���ǵ��������Ľ���������Ƚ���һ�ִ�res��max����
        for (int i = 1; i <= n; i ++) 
            res = max(res, f[i]);
        
        // �������LIS����-------����������
        for (int i = n; i; i --)
        {
            f[i] = 1;
            for (int j = n; j > i; j --)
                if (a[i] > a[j])
                    f[i] = max(f[i], f[j] + 1);
        }
        for (int i = 1; i <= n; i ++)
            res = max(res, f[i]);
        cout << res << endl;
    }
    
    return 0;
}