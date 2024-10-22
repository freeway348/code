// Dijkstra�㷨�����· 
// ��Ŀ������һ�� n ���㣬m ���ߵ�����ͼ��ͼ�п��ܴ����رߺ��Ի������б�Ȩ��Ϊ��������� 1 �ŵ㵽 n �ŵ����̾��룬����޷��� 1 �ŵ��ߵ� n �ŵ㣬����� -1
// ��Χ��1 <= n <= 500; 1 <= m <= 1e5 ---------- ����ͼ --------  �ڽӾ���
// ���룺��һ�а����������� n �� m�������� m �а����������� x,y,z����ʾ�� x �͵� y ֮����һ������ߣ����Ȩ���߳���Ϊ z
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 510;
int n,m;
int g[N][N]; // g[a][b]:��¼�� a ���� b �ı߳�
int dist[N]; // dist[i]�� 1 �ŵ㵽 i �ŵ����̾���
bool st[N]; // st[i]����¼�� i �Ƿ��Ѿ�Ϊ��̾��� 

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0; // 1 �ŵ������

    for (int i = 0; i < n; i ++) // ѭ�� n �Σ��� 1 �ŵ㵽�� n �������̾��붼�����
    {
        int t = -1; // ÿ��ѭ���ҵ�����һ������̾���
        for (int j = 1; j <= n; j ++) // ö��ÿһ����
            if (!st[j] && (t == -1 || dist[t] > dist[j])) // δ�� st ��ǵľ�������ĵ�
                t = j; // �� t ����������ľ���
        
        st[t] = true;

        for (int j = 1; j <= n; j ++)
            dist[j] = min(dist[j],dist[t] + g[t][j]); // ö��ÿһ���㣬�жϴ� 1 �ŵ�����������м�� t ��·����ֱ�ӵ� j �ŵ�ľ����ĸ�����
    }
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while(m --)
    {
        int a,b,c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c); // ����ر�����
    }
    int t = dijkstra();
    cout << t << endl;
    return 0;
}