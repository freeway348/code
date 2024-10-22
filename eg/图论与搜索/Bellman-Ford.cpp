// ��Ŀ������ n ���� m ���ߵ�����ͼ�����ܴ����رߺ��Ի�����Ȩ����Ϊ����������� 1 �ŵ㵽 n �ŵ����ྭ�� k ���ߵ���̾��룬����޷����� n �ŵ㣬����� -1
// ���ݷ�Χ�� 1 <= n,k <= 500; 1 <= m <= 1e4,����߳��ľ���ֵ������ 1e4
// �洢��ʽ�����ɣ�ֻҪ�ܱ��������б߾Ϳ���
// ����и�Ȩ��·�������·���ܲ�����(���磺��·Ϊ�� 1,2��-4����ÿ����һ�λ�·����̾���ͻ���̣������ڸû�·���ܽ�����ѭ��)
// n �ε��� ---------- ���ҵ����� n ���ߵ���̾���
// Bellman-Ford�㷨Ҳ���������Ҹ��� ------- ǰ n - 1 �θ������ҵ���̾��룬����� n �����ܸ�����̾��룬��ʱ�� n ����-----˵���� n + 1 ���㣬��ش��ڻ����������ڸ��º�ľ������̾��뻹�̣�˵��������Ǹ���
// һ����SPFA�㷨���Ҹ�����Bellman-Ford�㷨ʱ�临�Ӷ�̫��
// Bellman-Ford�㷨�ɵ����ǲ���ʽ��dist[b] <= dist[a] + w 
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 100010;

int n,m,k;
int dist[N],backup[N];

struct Edge
{
    int a,b,w;
}edges[M];

int bellman_ford()
{
    memset(dist, 0x3f,sizeof dist);
    dist[1] = 0; // �������
    for (int i = 0; i < k; i ++) // ��ྭ�� k ����
    {
        memcpy(backup,dist,sizeof dist);
        for (int j = 0; j < m; j ++) // �������б�
        {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b],backup[a] + w); // �ɳڲ���
            // ����һ��ѭ�����µĽ����������һ��ѭ��������һ��ѭ���еĸ��³����������----------���磺����ֻ�󾭹�һ���ߵ����·
            // �� 1 -> 2 = 1
            // 2 -> 3 = 1 ,
            // 1 -> 3 = 3
            // ��ʱ�����dist �����£��ͻᵼ�� 1 -> 3 �����·�� 1 -> 2 -> 3, ������ 1 -> 3,������������ߣ��ⲻ��������Ҫ�ģ�������Ҫ�� dist ���鱸�ݵ� backup ��

        }
    }
    if (dist[n] > 0x3f3f3f3f / 2) return -1; // ��� dist[x] = 0x3f3f3f3f, dist[n] = 0x3f3f3f3f, �� x -> n = - 50,�� dist[n] �ͻᱻ����Ϊ��0x3f3f3f3f - 50 
    // ��������Ҳ����� n �ŵ��·�������磺1 �ŵ���������֮��û�бߣ���������֮�䶼�бߣ������ܵ� n �ŵ㣬��ʱ���Ǽ��������n �� m ȡ���500 ��ȨֵΪ -1e4�������֪�����Ϊ -5e6����dist[n] = 0x3f3f3f3f - 5e6
    return dist[n];
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i ++)
    {
        int a,b,w;
        cin >> a >> b >> w;
        edges[i] = {a,b,w};
    }
    int t = bellman_ford();
    if (t == -1) cout << "impossible" << endl;
    else cout << t << endl;
    return 0;
}