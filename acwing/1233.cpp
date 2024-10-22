// //bfs1,参照y总,已AC
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <utility>
// using namespace std;
// const int N = 1010;
// pair<int,int> q[N * N];//记录走过的坐标
// char g[N][N];//存是否有岛屿
// int n;
// int d[N][N];//记录是否走过

// void check(int a, int b, int& total, int& bound)//bfs
// {
//     int hh = 0, tt = 0;
//     q[0] = {a, b};//小岛最左上角（起点
//     d[a][b] = 1;
//     while (hh <= tt)
//     {
//         total ++;
//         auto t = q[hh ++];
//         bool flag = false;
//         int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
//         for (int i = 0; i < 4; i ++)//查找 t 附近的陆地
//         {
//             int x = t.first + dx[i], y = t.second + dy[i];
//             if (g[x][y] == '.') 
//             {
//                 flag = true;
//                 continue;
//             }
//             if (d[x][y] == -1 && g[x][y] == '#' && x >= 0 && x < n && y >= 0 && y < n)
//             {
//                 q[++ tt] = {x,y};
//                 d[x][y] = 1;
//             }
//         }
//         if (flag) bound ++;
    
//     }
// }

// int main()
// {
//     int res = 0;
//     cin >> n;
//     for (int i = 0; i < n; i ++)
//         for (int j = 0; j < n; j ++)
//             cin >> g[i][j];
//     memset(d, -1, sizeof d);
//     for (int i = 0; i < n; i ++)
//         for (int j = 0; j < n; j ++)
//         {
//             if(g[i][j] == '#' && d[i][j] == -1)//找到岛屿的第一片陆地
//             {
//                 int total = 0, bound = 0;
//                 check(i,j,total,bound);
//                 if (total == bound) res ++;
//             }
//         }
//     cout << res;
//     return 0;
// }   

//bfs2,自作,已AC
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 1010;
pair<int,int> q[N * N];//记录走过的坐标
//如果pair数组q 不开 N * N 大小，就会爆内存，导致最后一个测试数据（1000 × 1000）矩阵读入不了在后边的岛屿
char g[N][N];//存是否有岛屿
int n;
int d[N][N];//记录是否走过
bool flag;

void check(int a, int b)//bfs
{
    int hh = 0, tt = 0;
    q[0] = {a, b};//小岛最左上角（起点
    d[a][b] = 1;
    while (hh <= tt)
    {
        auto t = q[hh ++];
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
        if (g[t.first][t.second + 1] == '#' && g[t.first + 1][t.second] == '#' && g[t.first - 1][t.second] == '#' && g[t.first][t.second - 1] == '#')
            flag = true;
        for (int i = 0; i < 4; i ++)//查找 t 附近的陆地
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (d[x][y] == -1 && g[x][y] == '#' && x >= 0 && x < n && y >= 0 && y < n)
            {
                q[++ tt] = {x,y};
                d[x][y] = 1;
            }
        }
    }
}

int main()
{
    int res = 0;
    cin >> n;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            cin >> g[i][j];
    memset(d, -1, sizeof d);
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
        {
            if(g[i][j] == '#' && d[i][j] == -1)//找到岛屿的第一片陆地
            {
                flag = false;
                check(i,j);
                if (!flag) res ++;
            }
        }
    cout << res;
    return 0;
}   

//dfs, 参考思路， 直接摘的别人代码
// #include<bits/stdc++.h>
// using namespace std;

// int n;
// char a[1010][1010]; //地图
// int vis[1010][1010]={0};  //标记是否搜过
// int d[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}}; //四个方向
// int flag;  //用于标记这个岛中是否被完全淹没
// void dfs(int x, int y){
//     vis[x][y] = 1;      //标记这个'#'被搜过。注意为什么可以放在这里
//     if(a[x][y+1]=='#' && a[x][y-1]=='#' && a[x+1][y]=='#' && a[x-1][y]=='#')
//         flag = 1;       //上下左右都是陆地，不会淹没
//     for(int i = 0; i < 4; i++){ //继续DFS周围的陆地
//         int nx = x + d[i][0], ny = y + d[i][1];
//       //if(nx>=1 && nx<=n && ny>=1 && ny<=n && vis[nx][ny]==0 && a[nx][ny]=='#') //题目说边上都是水，所以不用这么写了
//         if(vis[nx][ny]==0 && a[nx][ny]=='#') //继续DFS未搜过的陆地，目的是标记它们
//             dfs(nx,ny);
//     }
// }

// int main(){
//     cin >> n;
//     for(int i = 1; i <= n; i++)
//         for(int j = 1; j <= n; j++)
//             cin >> a[i][j];
//     int ans = 0 ;
//     for(int i = 1; i <= n; i++)  //DFS所有像素点
//         for(int j = 1; j <= n; j++)
//             if(a[i][j]=='#' && vis[i][j]==0){
//                 flag = 0;
//                 dfs(i,j);
//                 if(flag == 0)  //这个岛全部被淹
//                     ans++;     //统计岛的数量
//             }
//     cout<<ans<<endl;
//     return 0;
// }
