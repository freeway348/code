/*
    这场博弈中，若最小堆石子的数量 >= 2, 则 Alice 必胜，因为Alice 可以选择每次取最小堆的石子数 - 1，令 Bob只能取走一个石子
    若最小堆石子为 1， 

*/ 
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        int p[200010] = {};
        cin >> n;
        int c = 1;
        for (int i = 1; i <= n; i ++)
            cin >> p[i];
        sort(p + 1, p + n + 1);

        // 必须要去重，因为每次操作是对所有石子堆进行的，如果不去重，输出结果大概率错误
        int end = unique(p + 1,p + n + 1) - p - 1; // 不重复序列的元素的数量
        for (int i = 1; i <= end; i ++)
        {
            if (p[i] == c)
                c ++;
        }

        
        if (p[n] < c) // 如果石子堆是从 1 开始的连续 + 1 的序列，如： 1 2 3 4 5 6 7 8 9
            if (p[n] % 2 == 1) // 凭奇偶性判断胜负-----------因为每个人每次都只能拿 1 个
                cout << "Alice" << endl;
            else 
                cout << "Bob" << endl;
        else // 如果前几次均只能拿 1 个，但从第 i 次开始，最小石子堆的石子数 >= 2，则此时的先手即为必胜态
        {
            if (c % 2 == 1)
                cout << "Alice" << endl;
            else 
                cout << "Bob" << endl;
        }
    }
    return 0;
}