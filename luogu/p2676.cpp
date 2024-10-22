#include <iostream>
#include <algorithm>

using namespace std;

int a[100010];

int main()
{
    int n,k;
    cin >> n >> k;
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    sort(a, a + n,greater<int>( ) );
    int z = 0;
    for (int i = 0, sum = 0; i < n; i ++)
    {
        sum += a[i];
        z ++;
        if (sum >= k) break;
    }
    cout << z;
    return 0;
}