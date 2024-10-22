// ���У�����֤���Ϊ 1 ������û�б������������á�
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1e6 + 10;
typedef pair<int,int> PII;
int e[N],ne[N],idx, h[N];
int n,m;
bool st[N];
int q[N];
vector<PII> w;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx, idx ++;
}

void dfs(int u)
{
    st[u] = true;
    cout << u << ' ';
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
            dfs(j);
    }
}

void bfs()
{
    int hh = 0, tt = 0;
    memset(st,false,sizeof st);
    q[0] = 1;
    st[1] = true;
    while(hh <= tt)
    {
        int t = q[hh ++];
        cout << t << ' ';
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (!st[j])
            {
                q[++ tt] = j;
                st[j] = true;
            }
        }
    }
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;    
    for (int i = 0; i < m; i ++)
    {
        int x,y;
        cin >> x >> y;
        w.push_back({y,x});
    }
    sort(w.begin(),w.end(),greater<PII>() ); // ��Ϊ��ͷ�巨���ڽӱ��������Ҫ��С��������ڽӱ��ο����׾�Ҫ�Ӵ�С����
    for (int i = 0; i < m; i ++)
        add(w[i].second,w[i].first);
    dfs(1);
    
    cout << endl;
    bfs();
    
    return 0;
}
