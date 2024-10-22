#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n,m;
const int N = 1e3 + 10;
int dp[N][5];
int t;
string s[N];
string p = "narek"; // 不要忘了给终止符留一个位置

void solve()
{
    for (int i = 0; i < n; i ++) // 遍历所有行
    {
        for (int j = 0; j < 5; j ++) // 遍历五个字符 nerak
        {
            int next = j;
            for (int k = 0; k < m; k ++) // 遍历该行的所有字符
            {
                int xd = p.find(s[i][k]); // 是否找到narek中的任一字符
                if (xd == -1) continue; // 没找到就结束
            }
        }
    }
}

int main()
{
    cin >> t;
    while (t --)
    {
        memset(dp, -1e9, sizeof dp);
        dp[0][0] = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i ++)
            cin >> s[i];
        

    }


    return 0;
}