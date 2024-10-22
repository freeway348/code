// 题目：NIM游戏
// 异或操作(xor 或 ^) 任何数与 0 的异或都是其本身

// 有 n 堆石子，每 i 堆有 ai 个石子，每次可以从某一堆中取走若干个，先后手轮流取，最后无石子可取的人输
// 做法：将这 n 堆石子的数量异或起来（即 a1  xor  a2 xor . . .   xor  xn)，假如不为 0 ，则先手必胜，否则先手必败
// 现给出一个 x ，其二进制中最高一位 1 在第 k 位，则在 a1 ~ an 中必然存在一个数 ai, 其第 k 位是 1
// x 是所有堆的石子个数全部异或后得到的结果
// 所以 ai xor x < ai
// 每次从 ai 中拿走 ai - (ai xor x) 个石子，则第 i 堆中的石子就从 ai 个变成 ai xor x 个
// 这样做，则可得到：  a1 xor a2 xor … ai xor x xor … xor an = x xor x = 0;

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int res = 0;
    while(n --)
    {
        int x;
        cin >> x;
        res ^= x;
    }
    if (res) cout << "先手胜利" << '\n';
    else cout << "NO" << '\n';
    return 0;
}