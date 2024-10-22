// 例题： acwing 树的重心
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100010, M = 2 * N;
int n;
int h[N],e[M],ne[M],idx; // h ------- 邻接表的头节点， idx ------- 指向下一个点， e ------- 当前指向的值, ne --------- 下一个节点的值
bool st[N];// 存储一下遍历过的值
int ans = N; 

void add(int a, int b) // 在 a 所对应的邻接表中插入一个 b （头插法）-------- 即：一条 a 指向 b 的边
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

// 求出以 u 为根的子树中  点的数量
int dfs(int u)
{
    st[u] = true;
    int sum = 1; // 以 u 为节点的子树节点数量
    int res = 0; // res 为删去节点 u 之后每个连通图的最大值
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i]; // 当前节点的值
        if (! st[j]) // 如果没遍历过
        {
            // s 为子树 j 的节点总数
            int s = dfs(j); // 再以 j 为顶点的邻接表继续往下遍历，直到遍历到这条路的最后一个节点 
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum);
    ans = min(ans, res);
    return sum;
}

int main()
{
    cin >> n;
    memset(h, -1 ,sizeof h);
    for (int i = 0; i < n - 1; i ++) // n 个点， n - 1 条边
    {
        int a,b;
        cin >> a >> b;
        add(a,b);
        add(b,a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}