#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 20, M = 1 << N, INF = 0x3f3f3f3f;
int f[M][N], w[N][N];
int n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++)   
        for (int j = 0; j < n; j ++)
            cin >> w[i][j];

    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;//集合为 i 的情况下，j = 0 时车票总值即为0

    //例如，有5座城市，北京是第一座出发城市，则将2^0 = 1 记为出发点， 2^1为第二座城市， 2^2为第三座城市,以此类推，以二进制表示
    for (int i = 1; i < 1 << n; i += 2)
        for (int j = 0; j < n; j ++)//枚举每座城市，判断是否能从集合 i 中走到
            if ( i >> j & 1)//如果考虑的 i 座城市中有第 j + 1 座城市
                for (int k = 0; k < n; k ++)
                    if (i - (1 << j) >> k & 1) //判断集合 i 中将第 j + 1 座城市去掉之后是否仍能找到第 k + 1座城市，如果能找到，则说明 j + 1 与 k + 1 不是同一座城市,并且在集合 i 中
                    //如果能从集合 i 的起点到第 k + 1 座城市，则判断最少路费
                        // f[i][j]记录的是城市集合 i 中终点为城市 j + 1 的最少总路费
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);//w[k][j]代表从第 k + 1 座城市到第 j + 1 座城市的车费

    int res = INF;
    for (int i = 1; i < n; i ++)
        res = min(res, f[(1 << n) - 1][i] + w[i][0]);//求考虑了所有城市集合时，最后一个旅游城市为 i 的最少总路费
    cout << res << '\n';
    return 0;
}