// 题目：给出两个整数 n,m , 输入 m 个质数，求 1 ~ n 中能被这 m 个质数整除的数的个数
// 思路：可将这 k 个质数的倍数都放到其自己的集合中，再使用容斥原理
// 数据范围： 1 <= m <= 16, 1 <= n,pi <= 1e9 

// C(0 n) + C(1 n) + …… + C(n n) = 2^n; ---------- 可以理解为：1 个集合个数 + 2 个集合的交集的集合个数 + …… + n 个集合的交集的集合个数
// 所以，所有集合的个数和就是 2^n 个
// 可由 (a + b)^n 进行多项式展开，其系数之和即为组合数之和，且当 a = b = 1 时，可得其组合数之和为 2^n
// 同样的：当 a = 1, b = -1 时： 可得 C(0 n) - C(1 n) + C(2 n) - …… + (-1)^(2k)*C(2k n) + …… + (-1)^(n)*C(n n) = 0
// 由此可得： C(1 n) - C(2 n) + …… + (-1)^(k + 1)*C(k n) + …… + (-1)^(n + 1)*C(n n) = 1
// 该式可证明 容斥原理 最终得到的只会是一个总的大集合
// 求三个集合的交集：所有一个集合的和 - 所有两个集合交集的和 + 所有三个集合交集的和 - …… - 所有 2*n 个元素交集的和 + 所有 (2*n + 1) 个集合交集的和 
// 代码实现中，使用位运算更方便 
// 容斥原理 的时间复杂度为 O(2^m) 其中，m 为输入数的个数
// 1 ~ n 中能被 p 整除的数的个数为：(int) n / p (下取整)
// 计算每个集合的个数的时间复杂度为 O(k) --------- k 取决于给出的集合的个数

// >> 为右移运算符，效果为÷2， << 为左移运算符，效果为×2
#include <iostream>

using namespace std;
typedef long long LL;
const int N = 20;
int p[N];

int main()
{
    int n,m;
    LL res = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i ++)
        cin >> p[i]; 
    // 例如：若 i = （00101）B，则说明这是集合1和集合3的交集，然后再用for循环计算该集合中符合条件的数的个数
    for (int i = 1; i < 1 << m; i ++)
    {
        int t = 1, cnt = 0; 
        for (int j = 0; j < m; j ++)
        {
            // 因为当 j = 0 时，位运算的是 i 的最小位，即最右边的那位二进制，所以需要右移
            if (i >> j & 1)//如果涉及到(用到)第 j 个集合
            {
                cnt ++; //  记录涉及到的集合的个数
                // 例如：给定 n = 10，则其二进制为 1010, 若给出 3 个质数，则 i 的范围是 0 ~ 16, 当 i = 11 时，其二进制为 1011
                //      而经过 for(j……) 循环可得 t 的过程量及结果：t *= p[0], t *= p[1], t *= p[3],若给出质数为 2，3，5，则 t 最终值为 t = 30 > n = 10
                //      说明不可能取到这三个质数的集合
                if ((LL) t * p[j] > n) 
                {
                    t = -1;
                    break;
                }
                t *= p[j]; // t 中记录的是被用到的质数的乘积
            }
        }
        if (t != -1)
        {
            if (cnt % 2)//如果是奇数个集合的交集
                res += n / t;
            else
                res -= n / t;
        }
    }

    cout << res << '\n';

    return 0;
}