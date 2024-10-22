#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N],b[N];
int n,m;


bool check(int mid)
{
    long long res = 0;
    for (int i = 0; i < n; i ++)
        if (a[i] >= mid)
            res += (a[i] - mid) / b[i] + 1;
    return res >= m;//判断是否已经找到前 m 大的所有数
    //若res比m大，这说明mid取太小了
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++) 
        cin >> a[i] >> b[i];
    int l = 0, r = 1e6;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }    
    //最终得到的 l 和 r 是第 m 大的数
    long long res = 0,cnt = 0;
    for (int i = 0; i < n; i ++)
        if (a[i] >= r)
        {
            int c = (a[i] - r) / b[i] + 1;//项数
            int end = a[i] - (c - 1) * b[i];
            cnt += c;
            res += (long long)(end + a[i]) * c / 2;
        }
    cout << res - (cnt - m) * r;//将多加的数减去
    //如果刚好满足，则说明 cnt == m; 但若加的数 cnt > m，则说明 多加了 cnt - m 个 r,因为可能存在多个相同的 r，并且正常是只取其中一部分，但先前却将所有相同的 r 都加了
    return 0;
}