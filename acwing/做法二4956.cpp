//二分模板
#include <iostream>
#include <algorithm>
using namespace std;
int n;

int get (int a, int b)
{
    int l = 1,r = 1e9 + 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (a / mid <= b) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main()
{
    int a,b;
    int v_min = 1,v_max = 1e9;
    cin >> n;
    
    while (n --)
    {
        cin >> a >> b;
        v_min = max(v_min,get(a,b));
        v_max = min(v_max,get(a,b - 1) - 1);
    }
    cout << v_min << ' ' << v_max;
    return 0;
}
