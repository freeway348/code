/*
    �о� U �� D ���������������������������磺UUU��UDU��DUU......
    �����ҳ����ɣ�ÿ������һ�� U ��ʣ��Ӳ���� U �����������������仯�����������ӻ��Ǽ��٣�
    ���Կɵó����ۣ������ʼ״̬�� U ������Ϊ�������������ֱ�ʤ
*/
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i ++)
        {
            char x;
            cin >> x;
            if (x == 'U')
                ans ^= 1;
            else 
                ans ^= 0;
        }
        if (ans % 2 == 1) cout << "YES" << endl;
        else cout << "NO" << endl;  
    }
    return 0;
}