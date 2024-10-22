#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int n;
const int N = 251;
int f[N][N];
int s[N];


int main()
{
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i ++)  
    {
        cin >> s[i];
        f[i][i] = s[i];
        ans = max(ans, f[i][i]);
    }
    for (int len = 2; len <= n; len ++)
    {
        for (int i = 1; i + len - 1 <= n; i ++)
        {
            int l = i, r = i + len - 1;
            for (int k = l; k < r; k ++)
            {   
                if (f[l][k] == f[k + 1][r] && f[l][k] > 0)
                {
                    f[l][r] = max(f[l][r], f[l][k] + 1);
                    ans = max(ans, f[l][r]);
                }
            }
        }
    }
    cout << ans;

    return 0;
}