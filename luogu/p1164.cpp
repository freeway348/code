#include <iostream>

using namespace std;

const int N = 110;
int n,m;
int f[N];
int p[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> p[i];
    f[0] = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = m; j >= p[i]; j --)
            f[j] += f[j - p[i]];
    cout << f[m];
    return 0;
}