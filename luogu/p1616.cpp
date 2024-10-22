#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 2e7 + 10;
int t,m;
int a[N], b[N];
long long f[N];

int main()
{
    cin >> t >> m;
    for (int i = 1; i <= m; i ++)
        cin >> a[i] >> b[i];
    for (int i = 1; i <= m; i ++) // ±éÀúËùÓÐ²ÝÒ©
        for (int j = a[i]; j <= t; j ++)    
            f[j] = max(f[j], f[j - a[i]] + b[i]);
    cout << f[t];
    return 0;
}