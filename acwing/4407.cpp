#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long ll;

const int N = 5e4 + 10;
const int M = 1e6 + 7;//质数，求哈希值时减少哈希冲突
const int X = 1e9 + 1;//确保每一对 x,y 能唯一确定
int n,m;
int id[M];//存地雷下标
int p[M];
bool st[N];
ll h[M];//哈希数组

struct COOR
{
    int x,y,r;
}q[N];

ll get_key(int x,int y)//得到哈希值(哈希表中用)
{
    return (ll)x * X + y;//若是直接处理 x，y 则可能出现 x，y 坐标不同，但 x + y 的值相同，则无法区分 
}

int find(int x,int y)
{
    ll pos = get_key(x,y);
    int key = (pos % M + M) % M;
    while (h[key] != -1 && h[key] != pos)//找到pos哈希值所在的哈希表中的位置，否则找到一个空位以插入
    {
        key ++;
        if (key == M)
            key = 0;
    }
    return key;
}

bool check(int x,int y,int r, int xx, int yy) //排雷导弹 (x,y,r) 是否能炸到坐标为(xx,yy)的地雷
{
    int d = (x - xx) * (x - xx) + (y - yy) * (y - yy);
    return r * r >= d;
}

void bfs(int key)
{
    p[0] = key;
    int hh = 0, tt = 0;
    st[key] = true;

    while (hh <= tt)
    {
        auto t = p[hh ++];
        int x = q[t].x, y = q[t].y, r = q[t].r;
        for (int i = x - r; i <= x + r; i ++)
            for (int j = y - r; j <= y + r; j ++)
            {
                int pos = find(i,j);
                if (check(x,y,r,i,j) && !st[id[pos]] && id[pos])//若爆炸范围内有地雷并且未被引爆 
                {
                    st[id[pos]] = true;
                    p[++ tt] = id[pos];
                }
            }
    }
}


int main()
{
    cin >> n >> m;
    memset(h,-1,sizeof h);
    for (int i = 1; i <= n; i ++)
    {
        cin >> q[i].x >> q[i].y >> q[i].r;
        int key = find(q[i].x, q[i].y);
        if (h[key] == -1) h[key] = get_key(q[i].x,q[i].y);//如果在哈希表中没找到，则直接插入
        
        //难点
        //标记爆炸范围更大的地雷
        //没有被标记则标记，如果已被标记，则记录爆炸范围更大的那个地雷(爆炸时能将爆炸范围小的地雷一起引爆)
        if (!id[key] || q[id[key]].r < q[i].r)
        {
            id[key] = i;
        }

    }

    for (int i = 1; i <= m; i ++)
    {
        int x,y,r;
        cin >> x >> y >> r;
        for (int xx = x - r; xx <= x + r; xx ++)
            for (int yy = y - r; yy <= y + r; yy ++)
            {
                int key = find (xx, yy);
                if (id[key] && !st[id[key]] && check(x,y,r, xx, yy)) bfs(id[key]);

            }
    }
    int res = 0;
    for (int i = 1; i <= n; i ++)
    {
        int key = find(q[i].x, q[i].y);
        if (id[key] && st[id[key]])//如果是雷，并且已经引爆 
            res ++;
    }
    cout << res << '\n';
    return 0;
}