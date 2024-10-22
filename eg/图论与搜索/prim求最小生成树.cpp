// ������Ŀ:����һ�� n ���㣨1 ~ n�� m ���ߵ�����ͼ��ͼ�п��ܴ��� �ر� �� �Ի�����Ȩ����Ϊ����;����С�������ı�ȨȨ��֮�ͣ��������������� impossible


#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510,INF = 0x3f3f3f3f;

int g[N][N]; // g[a][b] : �ڽӾ����� a ���� b �ľ���
int dist[N]; // dist[j] : ����ǵ� j ���Ѵ�����С�������ĵ�ļ��ϵľ���
int n,m; 
bool st[N]; // st[j] : �жϵ� j �Ƿ������С�������ĵ㼯��

int prim()
{
    memset(dist, 0x3f, sizeof dist);

    int res = 0;

    for (int i = 0; i < n; i ++) // ���� n �Σ����� n - 1 ����
    {
        int t = -1;
        for (int j = 1; j <= n; j ++) // ����ÿһ����
            if (!st[j] && (t == -1 || dist[t] > dist[j])) // �ҵ������� �뼯������ĵ�
                t = j;
        
        if (i && dist[t] == 0x3f3f3f3f) return INF; // ���������ĵ���뼯�ϵ���̾���Ҳ���������˵���޷�������С������

        if (i) // ��Ϊ i = 0 ��һ��ѭ�������ڸ������е㵽 1 �ŵ�ľ��룬��ʱ dist ���黹δ���£����ݾ�Ϊ��������Բ���ȡ
            res += dist[t];

        for (int j = 1; j <= n; j ++)  dist[j] = min(dist[j],g[t][j]); // �� t �Ѿ����뵽��С�������ĵ㼯�У�����������Ǹ������е㵽��С�������ĵ㼯�ľ���

        st[t] = true;
    }
    return res;

}

int main()
{
    cin >> n >> m;

    memset(g, 0x3f, sizeof g);

    while(m --)
    {
        int a,b,c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b],c);
    }

    int t = prim();

    if (t == 0x3f3f3f3f) cout << "impossible" << endl;
    else cout << t << endl;

    return 0;
}