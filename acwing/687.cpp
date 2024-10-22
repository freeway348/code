#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 310;
int g[N][N];
char str[N][N];
int n;

void dfs(int a, int b)//扩展
{
    int t = g[a][b];
    g[a][b] = -1;
    if (t != 0) return;//如果中心是零，则扩展其八个方位，如果不是零，则扩展这个点即可
    for (int x = a - 1; x <= a + 1; x ++)
        for (int y = b - 1; y <= b + 1; y ++)
            if (x >= 0 && x < n && y >= 0 && y < n && g[x][y] != -1)
                dfs(x,y);

}

int main()
{
    int t;
    cin >> t;
    for (int cases = 1; cases <= t; cases ++)
    {
        cin >> n;
        for (int i = 0; i < n; i ++)
            scanf("%s",str[i]);
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j ++)
                if (str[i][j] == '*') g[i][j] = -1;
                else
                {
                    g[i][j] = 0;//防止上一次数据对这次产生影响
                    for (int x = i - 1; x <= i + 1; x ++)
                        for (int y = j - 1; y <= j + 1; y ++)
                            if (x >= 0 && x < n && y >= 0 && y < n && str[x][y] == '*') 
                                g[i][j] ++;
                } 
        int res = 0;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j ++)
                if (g[i][j] == 0)
                {
                    res ++ ;
                    dfs(i, j);
                }
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j ++)
                if (g[i][j] != -1)
                    res ++;
        cout << "Case #" << cases << ": " << res << '\n';
    }
    return 0;
}