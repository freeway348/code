#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n,m;
const int N = 1e3 + 10;
int dp[N][5];
int t;
string s[N];
string p = "narek"; // ��Ҫ���˸���ֹ����һ��λ��

void solve()
{
    for (int i = 0; i < n; i ++) // ����������
    {
        for (int j = 0; j < 5; j ++) // ��������ַ� nerak
        {
            int next = j;
            for (int k = 0; k < m; k ++) // �������е������ַ�
            {
                int xd = p.find(s[i][k]); // �Ƿ��ҵ�narek�е���һ�ַ�
                if (xd == -1) continue; // û�ҵ��ͽ���
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