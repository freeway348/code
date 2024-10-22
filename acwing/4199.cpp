#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1700;
int p[N]; // 存 a 和 b 的最大公约数的 约数
int cnt;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int a,b;
    int q;
    cin >> a >> b;
    int ans = gcd(a,b);//最大公约数
    for (int i = 1; i <= ans / i ; i ++)
    {
        if (ans % i == 0)
        {
            p[cnt ++] = i;
            if (i != ans / i) p[cnt ++] = ans / i; 
        }
    }
    sort(p, p + cnt);
    cin >> q;
    while (q --)
    {
        int hh ,tt;
        cin >> hh >> tt;
        int l = 0, r = cnt - 1;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (p[mid] <= tt) l = mid;//求出最后一个比右边界小的
            else r = mid - 1;
        }
        if (p[l] >= hh) cout << p[l] << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}