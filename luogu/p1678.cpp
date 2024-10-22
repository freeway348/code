#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
int w[N];
int n,m;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i ++)
        cin >> w[i];
    sort(w,w + n);
    LL res = 0;
    while(m --)
    {
        int x;
        cin >> x;
        int l = 0, r = n - 1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if (w[mid] > x) r = mid;
            else l = mid + 1;
        }
        if (x < w[0]) res += w[0] - x;//特判，避免学生成绩全零时仅有一所学校 这类情况,因为这时会取到第一位 w[0],并将其与 w[-1]比较，而由于仅有一个w[0]，所以必定比 0 大，这时用min就会出错
        else res += min(abs(w[l] - x), abs(w[l - 1] - x));
    }
    cout << w[-1] << endl;
    cout << res;
    return 0;
}