#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110; 
int n,v;
int a[N];
int b[N];

int main()
{
    cin >> n >> v;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        cin >> b[i];
    double x = 2e9;
    for (int i = 1; i <= n; i ++)
        x = min(x, (double)b[i] / a[i]);   
    double ans = 0;
    for (int i = 1; i <= n; i ++)
        ans += x * a[i];
    printf("%.1f", min(ans, (double)v));

    return 0;
}