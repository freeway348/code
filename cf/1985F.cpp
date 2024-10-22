#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;
typedef long long LL;
typedef pair<LL, int> PII;
int a[200010], b[200010];

int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        int n,m; // n ----- 生命值；m ------- 攻击次数
        set<PII> S;
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        cin >> n >> m;
        for (int i = 0; i < m; i ++)
        {
            cin >> a[i];
            S.insert({1,i});
        }
        for (int i = 0; i < m; i ++)
            cin >> b[i];
        int r = 0;
        while(n > 0)
        {
            //auto [z,i] = *S.begin(); // 将 set 数组 S 中的值分别赋给 z 和 i
            for (auto& t : S)
            {
                int z = t.first, i = t.second;
                n -= a[i];
                r = z;
                S.insert({z + b[i], i});
                S.erase({z,i}); 
                if (n < 0) break;
            }
                     
        }
        cout << r << endl;
    }


    return 0;
}