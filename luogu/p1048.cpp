#include <iostream>

using namespace std;

int v[1010],w[1010];
int f[1010];

int main()
{
    int t,m;
    cin >> t >> m; // t----时长；m-----数目
    for (int i = 1; i <= m; i ++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= m; i ++)
        for (int j = t; j >= 0; j --)
            if (j >= v[i])
                f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[t];
    return 0;
}