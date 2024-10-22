#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
const int N = 2e5 + 10;
int L,n,k;
int a[N];

bool check(int x)
{
    int ans = 0; // 增设路标数
    for (int i = 1; i < n; i ++)
        if (a[i + 1] - a[i] > x) 
            ans += (a[i + 1] - a[i] - 1) / x;
    return ans <= k;
}

int main()
{
    cin >> L >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    int l = 1, r = 1e7;
    while(l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid; // 如果满足条件
        else l = mid + 1;
    }
    cout << l;
    return 0;
}