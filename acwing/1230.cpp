#include <iostream>
using namespace std;
const int N = 1e6 + 10;
typedef long long ll;
int n,k;
ll p[N];//用于存储前缀和，考虑极端状况会有1e5个数量级为1e5的数的和，所以会达到1e10，会爆int
int cnt[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
    {
        cin >> p[i];
        p[i] += p[i - 1]; 
    }
    ll res = 0;
    //ant数组实际上是存储从 1~i 区间内的前缀和中，与p[i](右端点i)的差值能被 k 整除的区间左端点个数
    //所以若遇到从 1 ~ i 的第一个刚好能被 k 整除的区间和，此时 res += ans[0]; 理应有ant[0] = 1 作保
    cnt[0] ++;
    for (int i = 1; i <= n; i ++)
    {
        res += cnt[p[i] % k];       
        cnt[p[i] % k] ++;
    }
    cout << res;
    return 0;
}