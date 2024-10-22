// ���⣺���P10449
// ˼·�������һ�п������������ӵ�һ�е��Ƴ��ڶ��п��ص�״̬(�� ���� ����)���������һ�к��������ڶ��У���ʼ�����ڶ��У����Ƴ������п���״̬���Դ˵ó�����λ�õĿ���״̬,����ȷ�����Ƿ���ȫ1
// ������һ�п���״̬��֪������Ƴ����������еĿ���״̬
// ����ʱ�临�Ӷ�Ϊ����һ�еĿ����� �� �ܹ��ĵ����� ��  ÿ���ƿ�����Ӱ�쵽�ĵƵ����� �� ��������
//                      2^5 �� 25 �� 5 �� 500 = 400 0000 = 400 W
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 6;
char g[N][N], bg[N][N];

int hx[5] = {-1,0,0,0,1}, hy[5] = {0,1,0,-1,0};

void turn(int x, int y)
{
    for (int i = 0; i < 5; i ++)
    {
        int a = x + hx[i] , b = y + hy[i];
        if (a < 0 || a >= 5 || b < 0 || b >= 5) continue;
            g[a][b] ^= 1; // ��ת״̬( 0 --> 1; 1 --> 0 )�����������ַ����͵ļ������õ�ASCII�룬��1����ASCII����49����0����ASCII����48���������������һ�¸պ�
    }
}

int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        for (int i = 0; i < 5; i ++)
        scanf("%s", bg[i]);
        int res = 10; // ��ֵȡһ������ 6 ��ֵ�����ԣ�Ȼ����ֵ�滻���洢���ٷ�������
        for (int op = 0; op < 32; op ++) // ������һ�е����в���������� (�������ļ����ƽ��п���)
        {
            int cnt = 0; // �ı俪�صĴ���
            memcpy(g, bg, sizeof g);
            for (int j = 0; j < 5; j ++) // ������һ�е����λ��
                if (op >> j & 1) // �ƻ��еĲ���
                {
                    turn(0,j); // ���¿���---��ת
                    cnt ++;
                }
            for (int i = 0; i < 4; i ++) // ����
                for (int p = 0; p < 5; p ++)
                    if (g[i][p] == '0')
                    {
                        turn(i + 1, p);
                        cnt ++;
                    }
            bool suc = true;
            for (int i = 0; i < 5; i ++)
                if (g[4][i] == '0')
                    suc = false;
            if (suc && res > cnt) res = cnt; 

            
        }
        if (res > 6) res = -1;
        cout << res << endl;
    }
    
    return 0;
}