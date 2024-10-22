#include<iostream>
using namespace std;

const int N = 1010;

int n, m;
int f[N][N], v[N], w[N];
// f[i][j]代表前i个物品，一共j的背包体积，最多能拿到的最大价值

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ )
        cin >> v[i] >> w[i];
        
    for(int i = 1; i <= n; i ++)
        for(int j = 0; j <= m; j ++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= v[i])
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    cout << f[n][m] << endl;
    return 0;
}
