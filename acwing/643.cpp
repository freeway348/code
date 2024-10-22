#include <iostream>
#include <cstring>
using namespace std;

const int N = 110;
char g[N][N];
bool st[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int r,c;

void dfs(int a, int b)
{
    st[a][b] = true;
    for (int i = 0; i < 4; i ++)
    {
        int x = a + dx[i], y = b + dy[i];
        if (x >= 0 && x < r && y >= 0 && y < c && g[x][y] == '1' && !st[x][y])
            dfs(x, y);
    }
}

int main()
{
    int t;
    cin >> t;
    for (int cases = 1; cases <= t; cases ++)
    {
        cin >> r >> c;
        for (int i = 0; i < r; i ++)
            cin >> g[i];
        int n;
        cin >> n;
        cout << "Case #" << cases << ":" << '\n';
        char op[2];
        for (int i = 0; i < n; i ++)
        {
            cin >> op;
            if (op[0] == 'M')
            {
                int a,b,c;
                cin >> a >> b >> c;
                g[a][b] = c + '0';
            }
            else if (op[0] == 'Q')
            {
                memset(st,false,sizeof st);
                int res = 0;
                for (int x = 0; x < r; x ++)
                    for (int y = 0; y < c; y ++)
                        if (g[x][y] == '1' && !st[x][y])
                        {
                            res ++;
                            dfs(x, y);
                        }
                cout << res << '\n';
            }
        }
    }
    return 0;
}