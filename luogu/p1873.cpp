#include <iostream>

using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
int p[N];
int n;
LL m;

LL check(int x)//得到的树总长度
{
    LL res = 0;
    for (auto t : p)
        if (x < t) res += t - x;
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++)
        cin >> p[i];
    int l = 0, r = 4e5;
    while (l < r)   // 最终得到的 l 是正好大于等于 m 的第一个数（再低 1 米也拿不到 m 米的木材了）
    {
        int mid = l + r + 1 >> 1;
        if (check(mid) >= m) l = mid; // 如果得到的树木总长度比 m 更长，则锯树点再往上,不加等号判断会出错
        // 若判断不加等号，则得到的 l - 1 正好是能拿到 m 米的木材时的最高高度，这跟我们要求的最低要求高度相违背
        else r = mid - 1;
    }    
    cout << l ;
    return 0;
}