// 题目：
// 相应例题：洛谷P10446
/*
    求 a × b mod p 的值
    
    输入：
    第一行输入整数 a，第二行输入整数 b，第三行输入整数 p

    输出：
    输出一个数，表示 a^b % p 的值

    数据范围:
    1 <= a,b,p <= 1e18

    样例：
        输入：
        3
        4
        5
        输出：
        2
    
    做法：龟速乘 -------- 用加法来实现乘法
    相较于正常的快速幂求法(用乘法实现，时间复杂度位O(1))，这种位运算乘法能处理的数据范围更大,但速度更慢，时间复杂度为O(logn)
*/
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

LL qadd(LL a, LL b, LL p)
{
    LL res = 0;
    while(b)
    {
        if (b & 1) res = (res + a) % p;
        a = (a + a) % p;
        b >>= 1; 
    }
    return res;
}

int main()
{
    LL a,b,p;
    cin >> a >> b >> p;
    cout << qadd(a,b,p);
    return 0;
}
