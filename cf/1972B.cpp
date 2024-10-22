/*
    列举 U 和 D 的所有组合情况（总数三个）例如：UUU，UDU，DUU......
    可以找出规律：每次拿走一个 U ，剩下硬币中 U 的数量总是奇数个变化（不论是增加还是减少）
    所以可得出结论：如果初始状态下 U 的数量为奇数个，则先手必胜
*/
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i ++)
        {
            char x;
            cin >> x;
            if (x == 'U')
                ans ^= 1;
            else 
                ans ^= 0;
        }
        if (ans % 2 == 1) cout << "YES" << endl;
        else cout << "NO" << endl;  
    }
    return 0;
}