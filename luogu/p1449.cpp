// 数组模拟栈
// #include <iostream>
// #include <cstring>

// using namespace std;

// const int N = 110;
// int stac[N];
// int idx;

// int main()
// {
//     char x;
//     int a,b;
//     while(cin >> x, x != '@')
//     {
//         if (x == '.') idx ++;
//         if (x >= '0' && x <= '9')
//             stac[idx] = stac[idx] * 10 + x - '0';
//         else if (x == '+')
//         {
//             a = stac[-- idx];
//             b = stac[-- idx];
//             stac[idx ++] = a + b;
//             stac[idx] = 0;
//         }
//         else if (x == '-')
//         {
//             a = stac[-- idx];
//             b = stac[-- idx];
//             stac[idx ++] = b - a;
//             stac[idx] = 0;
//         }
//         else if (x == '*')
//         {
//             a = stac[-- idx];
//             b = stac[-- idx];
//             stac[idx ++] = a * b;
//             stac[idx] = 0;
//         }
//         else if (x == '/')
//         {
//             a = stac[-- idx];
//             b = stac[-- idx];
//             stac[idx ++] = b / a;
//             stac[idx] = 0;
//         }
//     }   
//     cout << stac[0] << endl;
//     return 0;
// }




// STL-------------stack 
#include <stack>
#include <iostream>
#include <cstring>

using namespace std;

stack<int> q;

int main()
{
    char x;
    int a,b,c = 0;
    while(cin >> x, x != '@')
    {
        if (x == '.') q.push(c), c = 0; // 记得重新化0
        if (x >= '0' && x <= '9')
            c = c * 10 + x - '0';
        else if (x == '+')
        {
            a = q.top(), q.pop();
            b = q.top(), q.pop();
            q.push(a + b);
        }
        else if (x == '-')
        {
            a = q.top(), q.pop();
            b = q.top(), q.pop();
            q.push(b - a);
        }
        else if (x == '*')
        {
            a = q.top(), q.pop();
            b = q.top(), q.pop();
            q.push(a * b);
        }
        else if (x == '/')
        {
            a = q.top(), q.pop();
            b = q.top(), q.pop();
            q.push(b / a);
        }
    }
    cout << q.top() << endl;
    return 0;
}