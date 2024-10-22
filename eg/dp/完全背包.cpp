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
        
    for(int i = 1; i <= n; i ++ )
        for(int j = 0; j <= m; j ++ )
            for(int k = 0; k * v[i] <= j; k ++ ) 
	//一共最多可选k个，从0个开始选，直到选完k个，比较所有取值的f值，以求出最大获利
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
                //求出每一个 f[i][j]
    cout << f[n][m] << endl;
    return 0;
}
