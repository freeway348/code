#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int a,b;
    cin >> n;
    int v_min = 1,v_max = 1e9;
    while (n --)
    {
        cin >> a >> b;
        v_min = max(v_min,a / (b + 1) + 1);
        v_max = min(v_max,a / b);
    }
    cout << v_min << ' ' << v_max;
    return 0;
}