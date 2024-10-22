// acwing 99

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 5010;
int s[N][N];

int main()
{
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i ++)
    {
        int x,y,w;
        cin >> x >> y >> w;
        x ++, y ++; // �� (1��1) Ϊԭ��
        s[x][y] += w;
    }
    // Ԥ����ǰ׺��
    for (int i = 1; i <= 5001; i ++)
        for (int j = 1; j <= 5001; j ++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j];
    int res = 0;
    for (int i = m; i <= 5001; i ++) // ը����ը��Χ�Ǳ߳�Ϊ m �������Σ������ֻ��Ӱ�쵽�߳�Ϊ (m - 1) �������η�Χ  
        for (int j = m; j <= 5001; j ++)
            res = max(res, s[i][j] - s[i - m][j] - s[i][j - m] + s[i - m][j - m]);
        
            
    cout << res;
    return 0;
}