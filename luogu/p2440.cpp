#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int p[N];
int n,k;

int check(int x) // 切出的原木数量
{
    int res = 0;
    for (auto t : p)
        res += t / x;
    return res;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i ++)
        cin >> p[i];
    int l = 1, r = 1e8;
    while(l < r)
    {
        int mid = l + r >> 1;
        if (check(mid) < k) r = mid;
        else l = mid + 1;
    }
    cout << l - 1;
    return 0;
}