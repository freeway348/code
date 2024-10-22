#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#define mod 100003
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

const int N = 1e6 + 10, M = 2e7 + 10;
int idx,e[M],ne[M],h[M],w[M],dist[M];
int n,m;
int ans[M];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = 1, h[a] = idx ++; 
}

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0; // 1 �ŵ������
    ans[1] = 1;
    priority_queue<PII,vector<PII>, greater<PII> > heap;
    heap.push({0,1}); // first ��Ȩֵ���� 1 �ŵ㵽�õ����̾��룩,second ��� i �ŵ� ---------- ��ΪС���ѵ��������Ƚ� first ��С��������֮������second
    
    while(heap.size())
    {
        auto t = heap.top(); // ÿ���ҵ�һ������̾���
        heap.pop();
        int ver = t.second, distance = t.first;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                ans[j] = ans[ver]; // ������·���£������·������ҲҪ����
                heap.push({dist[j],j});

            }
            else if (dist[j] == distance + w[i])
            {
                ans[j] = (ans[j] + ans[ver]) % mod; // ����ӵ� ver ��Ȼ���ߵ��� j ���������·���������
            }
        }

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m --)
    {
        int a,b;
        cin >> a >> b;
        add(a,b);
        add(b,a);
    }
    dijkstra();
    for (int i = 1; i <= n; i ++)
        cout << ans[i] << endl;
    return 0;
}