// acwing 1018
#include <iostream>
#include <cstring>

using namespace std;

const int N = 110, INF = 1e9;

int a[N][N], f[N][N];
int n;

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            scanf("%d", &a[i][j]);

    // ��ʼ��Ϊ������
    memset(f,0x3f,sizeof f);            
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
        {
            if (i == 1 && j == 1) f[i][j] = a[i][j];
            else f[i][j] = min(f[i - 1][j], f[i][j - 1]) + a[i][j]; 
        }
    // Ҳ���Բ�����ֵ0x3f������д��
    /*
    ȫ�ֱ�����const int INF = 1e9 // �����

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (i == 1 && j == 1) f[i][j] = a[i][j]; // �������Ͻǵĵ�
            else 
            {
                f[i][j] = INF;
                if (i > 1) // ���ڵ�һ��ʱ�����ܴ��ϱ�����
                    f[i][j] = min(f[i][j], f[i - 1][j] + a[i][j]);
                if (j > 1) // ���ڵ�һ��ʱ�����ܴ���߹���
                    f[i][j] = min(f[i][j], f[i][j - 1] + a[i][j]);
            }
        
    
    */

    printf("%d", f[n][n]);

    return 0;
}