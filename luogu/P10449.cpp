// 例题：洛谷P10449
// 思路：假设第一行开关已锁死，从第一行递推出第二行开关的状态(按 或者 不按)，遍历完第一行后，再锁死第二行，开始遍历第二行，递推出第三行开关状态，以此得出所有位置的开关状态,即可确定灯是否能全1
// 即：第一行开关状态已知，则可推出其他所有行的开关状态
// 所以时间复杂度为：第一行的可能数 × 总共的灯数量 ×  每个灯开关能影响到的灯的数量 × 总数据量
//                      2^5 × 25 × 5 × 500 = 400 0000 = 400 W
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 6;
char g[N][N], bg[N][N];

int hx[5] = {-1,0,0,0,1}, hy[5] = {0,1,0,-1,0};

void turn(int x, int y)
{
    for (int i = 0; i < 5; i ++)
    {
        int a = x + hx[i] , b = y + hy[i];
        if (a < 0 || a >= 5 || b < 0 || b >= 5) continue;
            g[a][b] ^= 1; // 反转状态( 0 --> 1; 1 --> 0 )，并且由于字符串型的计算是用的ASCII码，“1”的ASCII码是49，“0”的ASCII码是48，所以用异或运算一下刚好
    }
}

int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        for (int i = 0; i < 5; i ++)
        scanf("%s", bg[i]);
        int res = 10; // 初值取一个大于 6 的值都可以，然后逐值替换，存储最少方案步数
        for (int op = 0; op < 32; op ++) // 遍历第一行的所有操作方案组合 (即：对哪几个灯进行开关)
        {
            int cnt = 0; // 改变开关的次数
            memcpy(g, bg, sizeof g);
            for (int j = 0; j < 5; j ++) // 遍历第一行的五个位置
                if (op >> j & 1) // 计划中的操作
                {
                    turn(0,j); // 按下开关---反转
                    cnt ++;
                }
            for (int i = 0; i < 4; i ++) // 递推
                for (int p = 0; p < 5; p ++)
                    if (g[i][p] == '0')
                    {
                        turn(i + 1, p);
                        cnt ++;
                    }
            bool suc = true;
            for (int i = 0; i < 5; i ++)
                if (g[4][i] == '0')
                    suc = false;
            if (suc && res > cnt) res = cnt; 

            
        }
        if (res > 6) res = -1;
        cout << res << endl;
    }
    
    return 0;
}