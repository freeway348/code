// Dijkstra�㷨�����· 
// ��Ŀ������һ�� n ���㣬m ���ߵ�����ͼ��ͼ�п��ܴ����رߺ��Ի������б�Ȩ��Ϊ��������� 1 �ŵ㵽 n �ŵ����̾��룬����޷��� 1 �ŵ��ߵ� n �ŵ㣬����� -1
// ��Χ��1 <= n <= 2e3; 1 <= m <= 1e5,�߳�����ֵ������ 1e5  
// ���룺��һ�а����������� n �� m�������� m �а����������� x,y,z����ʾ�� x �͵� y ֮����һ������ߣ����Ȩ���߳���Ϊ z
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 100010;
int n,m;
LL idx,e[N],ne[N],h[N],w[N]; // w ��Ȩֵ
LL dist[N],cnt[N]; // dist[i]�� 1 �ŵ㵽 i �ŵ����̾���; cnt[i] : ���� i ������·�����˶�������
bool st[N]; 

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx, idx ++;
}

bool spfa()
{
     
    queue<int> q;
    q.push(1);
    dist[1] = 0; // �ǵ�Ҫ�Ƚ���֪���ľ�������Ϊ 0������������¾�����ܻ����
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
    int t;
    cin >> t;
    while(t --)
    {
        idx = 0;
        memset(e, 0, sizeof e);
        memset(ne, 0, sizeof ne);
        memset(w, 0, sizeof w);
        memset(st,false,sizeof st);
        memset(cnt, 0, sizeof cnt);
        memset(dist, 0x3f, sizeof dist);
        cin >> n >> m;
        memset(h, -1, sizeof h);
        while(m --)
        {
            int a,b,c;
            cin >> a >> b >> c;
            if (c >= 0)
            {
                add(a,b,c);
                add(b,a,c);
            }
            else add(a,b,c);
        }
        if (spfa()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}