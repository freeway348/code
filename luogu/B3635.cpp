#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;
int n;
int f[N];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i ++)
    {
        if (i >= 11)
            f[i] = min(f[i - 1], min(f[i - 5], f[i - 11])) + 1;
        else if (i >= 5)
            f[i] = min(f[i - 1], f[i - 5]) + 1;
        else 
            f[i] = f[i - 1] + 1;
    }
    
    cout << f[n];
    return 0;
}