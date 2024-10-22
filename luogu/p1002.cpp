#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 40;
long long f[N][N];
bool st[N][N];
int n[8] = {-2,-2,-1,-1,1,1,2,2};
int m[8] = {1,-1,2,-2,2,-2,1,-1};
int bx,by,hx,hy;

int main()
{
    cin >> bx >> by >> hx >> hy; 
    bx += 2, by += 2, hx += 2, hy += 2;
    st[hx][hy] = true;
    for (int i = 0; i < 8; i ++)
    {
        int u = hx + n[i];
        int j = hy + m[i];
        st[u][j] = true;
    }
    f[2][1] = 1;
    for (int i = 2; i <= bx; i ++)
        for (int j = 2; j <= by; j ++)
        {
            if (st[i][j])
                continue;
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    cout << f[bx][by];
    return 0;
}