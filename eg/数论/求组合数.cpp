//给出 a 和 b 要求输出 C(b a) 模 1e9 + 7 的值 ---------- C(b a) = b! / ((b - a)! * a!)
//递推公式: C(b a) = C(b a-1) + C(b-1 a-1)
//取值： 1 <= b <= a <= 2000(2e3);  1 <= n <=100000(1e5)
//用递推,时间复杂度为O(n^2)
#include <iostream>
using namespace std;

const int N = 2010, mod = 1e9 + 7;
int p[N][N];

void init()//杨辉三角法
{
    for (int i = 0; i < N; i ++)
        for (int j = 0; j <= i; j ++)
        {
            if (!j) p[i][j] = 1;//如果C(b a)中，b == 0，则结果为 1，如果C(b a)中 a 为 0， 则结果为 0
            else p[i][j] = (p[i - 1][j] + p[i - 1][j - 1]) % mod;//由递推公式求得 C(j i) --------- i 个里边选 j 个，分两种情况：包含第 j 个和不包含第 j 个
         }
}

int main()
{
    init();
    int n;
    cin >> n;
    while(n --)
    {
        int a,b;
        cin >> a >> b;//求C(b a)
        cout << p[a][b] << '\n';
    }
    return 0;
}