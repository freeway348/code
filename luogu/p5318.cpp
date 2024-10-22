// 特判：不保证编号为 1 的文章没有被其他文章引用。
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
    sort(w.begin(),w.end(),greater<PII>() ); // 因为是头插法建邻接表，所以如果要从小到大遍历邻接表，参考文献就要从大到小排序
    for (int i = 0; i < m; i ++)
        add(w[i].second,w[i].first);
    dfs(1);
    
    cout << endl;
    bfs();
    
    return 0;
}
