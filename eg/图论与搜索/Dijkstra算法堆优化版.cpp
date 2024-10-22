// Dijkstra�㷨�����· 
// ��Ŀ������һ�� n ���㣬m ���ߵ�����ͼ��ͼ�п��ܴ����رߺ��Ի������б�Ȩ��Ϊ��������� 1 �ŵ㵽 n �ŵ����̾��룬����޷��� 1 �ŵ��ߵ� n �ŵ㣬����� -1
// ��Χ��1 <= n <= 1e6; 1 <= m <= 1e6 ---------- ϡ��ͼ ----------- �ڽӱ�
// ���룺��һ�а����������� n �� m�������� m �а����������� x,y,z����ʾ�� x �͵� y ֮����һ������ߣ����Ȩ���߳���Ϊ z
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int,int> PII;
const int N = 100010;
int n,m;
int idx,e[N],ne[N],h[N],w[N]; // w ��Ȩֵ
int dist[N]; // dist[i]�� 1 �ŵ㵽 i �ŵ����̾���
bool st[N]; // st[i]����¼�� i �Ƿ��Ѿ�Ϊ��̾��� 

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx, idx ++;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0; // 1 �ŵ������

    priority_queue<PII,vector<PII>, greater<PII> > heap;
    heap.push({0,1}); // first ��Ȩֵ���� 1 �ŵ㵽�õ����̾��룩,second ��� i �ŵ� ---------- ��ΪС���ѵ��������Ƚ� first ��С��������֮������second
    
    while(heap.size())
    {
        auto t = heap.top(); // ÿ���ҵ�һ������̾���
        heap.pop();
        int ver = t.second, distance = t.first;
        if (st[ver]) continue;

        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j],j});
            }
        }

    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m --)
    {
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
    }
    int t = dijkstra();
    cout << t << endl;
    return 0;
}