#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int w[1010][1010];
int f[1010][1010];
int sum;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= i; j ++)
            cin >> w[i][j];
    f[1][1] = w[1][1];
    for (int i = 2; i <= n; i ++)
        for (int j = 1; j <= i; j ++)
        {
            if (j == 1) f[i][j] = f[i - 1][j] + w[i][j];
            else if (j == i) f[i][j] = f[i - 1][j - 1] + w[i][j];
            else 
                f[i][j] = max(f[i - 1][j] + w[i][j], f[i - 1][j - 1] + w[i][j]);
            if (i == n)
                sum = max(sum, f[i][j]);
        }
    cout << sum;
    return 0;
}