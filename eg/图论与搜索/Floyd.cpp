/*
����һ��n����m���ߵ�����ͼ��ͼ�п��ܴ����رߺ��Ի�����Ȩ����Ϊ������

�ٸ���k��ѯ�ʣ�ÿ��ѯ�ʰ�����������x��y����ʾ��ѯ�ӵ�x����y����̾��룬���·�������ڣ��������impossible����

���ݱ�֤ͼ�в����ڸ�Ȩ��·��
*/

/*
���룺
��һ�а�����������n��m��k

������m�У�ÿ�а�����������x��y��z����ʾ��x�͵�y֮�����һ������ߣ��߳�Ϊz��

������k�У�ÿ�а�����������x��y����ʾѯ�ʵ�x����y����̾��롣

�����
��k�У�ÿ�����һ����������ʾѯ�ʵĽ������ѯ������䲻����·�����������impossible����
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 210,INF = 1e9; 
int d[N][N];
int n,m,Q;

void floyd()
{
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
    cin >> n >> m >> Q;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;

    while(m --)
    {
        int a,b,w;
        cin >> a >> b >> w;
        
        d[a][b] = min(d[a][b],w);
    }

    floyd();

    while(Q--)
    {
        int a,b;
        cin >> a >> b;
        if (d[a][b] > INF / 2) cout << "impossible" << endl;//�����и�Ȩ�ߴ�������Լ���INF/2Ҳ�ܺ���
        else cout << d[a][b] << endl;
    }
    return 0;
}