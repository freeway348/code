#include <iostream>
#include <cstring>
#include <utility>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 21, M = N*N*N;

struct Node 
{
    int a,b,c;
}q[M];//因为要存储a，b，c各个0 ~ 21的情况，合计共有pow(21,3)种情况，所以用M
bool st[N][N][N];
// int W[3], w[3];//分别记录三个桶的容量以及桶中的牛奶的量

int main()
{
    int A,B,C;
    cin >> A >> B >> C;
    q[0] = {0,0,C};
    int hh = 0,tt = 0;
    int W[3] = {A,B,C};
    st[0][0][C] = true;

    while(hh <= tt)
    {
        auto t = q[hh ++];
        for (int i = 0; i < 3; i ++)
            for (int j = 0; j < 3; j ++)
                if (i != j)//将第i桶中的牛奶倒到第j桶中
                {
                    int w[3] = {t.a,t.b,t.c};//因为可能要回溯，所以得定义在if里，与t保持一致，否则在最外层while中定义会出bug-----只能存第一个情况
                    int r = min(w[i],W[j] - w[j]);
                    w[i] -= r, w[j] += r;
                    int a = w[0], b = w[1], c = w[2];
                    if (! st[a][b][c])
                    {
                        st[a][b][c] = true;
                        q[++ tt] = {a,b,c};
                    }
                }
    }
    for (int i = 0; i < N; i ++)
        for (int j = 0; j < N; j ++)
        if (st[0][j][i])
        {
            cout << i << ' ';
        }
    return 0;
}