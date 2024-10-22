// // 法1:遍历每一行的每一列,效率更高
// #include <iostream>

// using namespace std;

// const int N = 20;
// int n; // 有 n × n 个正方形矩阵 
// char g[N][N]; // 记棋盘上的皇后以及空位
// bool col[N], dg[N],udg[N]; //列，对角线，反对角线 

// void dfs(int u)
// {
//     if (u == n) // 如果 0 ~ n - 1 层都已经完成了，就退出
//     {
//         for (int i = 0; i < n; i ++) cout << g[i] << endl;
//         cout << endl;
//         return ;
//     }
//     for (int i = 0; i < n; i ++) // 遍历每一列
//     {
//         if (!col[i] && !dg[u + i] && !udg[n + i - u])
//         {
//             g[u][i] = 'Q';
//             col[i] = dg[u + i] = udg[n + i - u] = true;
//             dfs(u + 1);
//             g[u][i] = '.';
//             col[i] = dg[u + i] = udg[n + i - u] = false;
//         }
//     }
// }

// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; i ++)
//         for (int j = 0; j < n; j ++)
//             g[i][j] = '.';
//     dfs(0); // 从第 0 行开始枚举每一行

//     return 0;
// }


// 法2：遍历每一个格子，然后选择放或不放
#include <iostream>

using namespace std;

const int N = 20;
int n; // 有 n × n 个正方形矩阵 
char g[N][N]; // 记棋盘上的皇后以及空位
bool row[N],col[N], dg[N],udg[N]; //列，对角线，反对角线 

void dfs(int x, int y, int s) // x -------- 行， y --------- 列， s ------- 已放皇后个数
{
    if (y == n) 
    {
        y = 0; 
        x ++;
    }
    if (x == n)
    {
        if (s == n)
        {
            for (int i = 0; i < n; i ++) cout << g[i] << endl;
            cout << endl;
        }
        return ;
    }

    // 不放皇后
    dfs(x,y + 1,s);

    // 放皇后
    if (!row[x] && !col[y] && !dg[x + y] && !udg[n + x - y])
    {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[n + x - y] = true;
        dfs(x, y + 1, s + 1);
        g[x][y] = '.';
        row[x] = col[y] = dg[x + y] = udg[n + x - y] = false;
    }

}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            g[i][j] = '.';
    dfs(0,0,0); // 从第 0 行开始枚举每一行

    return 0;
}
