#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int p[N];
int n,m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i ++)
        cin >> p[i];
    while(m --)
    {
        int x,k = 0;
        cin >> x;
        int l = 0, r = n - 1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if (p[mid] >= x) r = mid;
            else l = mid + 1;
            if (p[mid] == x) k = 1;
        }
        if (k) cout << l + 1 << ' ';
        else cout << -1 << ' ';
    }
    return 0;
}