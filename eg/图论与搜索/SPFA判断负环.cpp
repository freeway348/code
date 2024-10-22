// Dijkstra�㷨�����· 
// ��Ŀ������һ�� n ���㣬m ���ߵ�����ͼ��ͼ�п��ܴ����رߺ��Ի������б�Ȩ��Ϊ��������� 1 �ŵ㵽 n �ŵ����̾��룬����޷��� 1 �ŵ��ߵ� n �ŵ㣬����� -1
// ��Χ��1 <= n <= 2e3; 1 <= m <= 1e5,�߳�����ֵ������ 1e5  
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
int dist[N],cnt[N]; // dist[i]�� 1 �ŵ㵽 i �ŵ����̾���; cnt[i] : ���� i ������·�����˶�������
bool st[N]; 

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx, idx ++;
}

bool spfa()
{
     
    queue<int> q;
    for(int i = 1; i <= n; i ++)
    {
        st[i] = true;
        q.push(i); // �����е�������ʼ�㼯�����ж�ÿ����Ϊ����·���Ƿ���ڸ���
    }
    while(q.size())
    {
        auto t = q.front();
        q.pop();

        st[t] = false; // ����֮����Ϊ false

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1; // ��������ˣ�˵����ԭ����·������һ����
                if (cnt[j] >= n) return true; // �������n ���ߣ���˵���� n + 1 ���㣬�ض���һ������������Σ���˵�����ָ���
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
                
        }
        
    }
    return false;
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
    if (spfa()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}