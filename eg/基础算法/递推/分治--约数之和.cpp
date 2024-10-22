// 解题思路：分治思想 ----------- 典型例题：快排，归并排序 
// 即：将一个问题分为若干个结构相同的子问题，直至递归到一个很小的可得出结论的子问题
// 题目: 给出两个自然数 A 和 B，S 是 A^B 的所有约数之和，求出 S mod 9901 的值
// 范围： 0 <= A,B <= 5e7
/*
    样例：
    输入：2 3
    输出：15
*/ 
#include <iostream>

using namespace std;

const int mod = 9901;

int qmi(int a, int b)
{
    int res = 1;
    a %= mod; // 避免 a 的初始值大，导致 a * a 爆 int
    while(b)
    {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// 分治思想的体现
int sum(int p, int k)
{
    // 特判
    if (k == 1) return 1;
    // 偶数
    if (k % 2 == 0) return (1 + qmi(p, k / 2)) * sum(p, k / 2) % mod;
    // 奇数
    return (sum(p, k - 1) + qmi(p, k - 1)) % mod;
}

int main()
{
    int a,b;
    cin >> a >> b;
    int res = 1;
    for (int i = 2; i <= a / i; i ++) // 对 a 分解质因数
    {
        if (a % i == 0)
        {
            int s = 0;
            while(a % i == 0)
            {
                s ++;
                a /= i;
            }
            res = res * sum(i, b * s + 1) % mod;
        }
    }
    if (a > 1) res = res * sum(a, b + 1) % mod;
    if (a == 0) res = 0;
    cout << res;
    return 0;
}