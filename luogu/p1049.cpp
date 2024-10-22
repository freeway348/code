#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 1e6 + 10;
int n,v;
int a[N], f[N];

int main()
{
    cin >> v;
    cin >> n;
    for (int i = 0; i < n; i ++)    
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i ++)
        for (int j = v; a[i] <= j; j --)
        {
            f[j] = max(f[j - a[i]] + a[i], f[j]);
        }
    cout << v - f[v];
    return 0;
}