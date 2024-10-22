//时间复杂度为O(logn)
//扩展欧几里得算法：给出一对a,b，要求求出一对非零整数 x，y 使得 a*x + b*y = d = N * gcd(a,b),其中x,y是能取到的最小值(因为 a*x + b*y = n*gcd(a,b) )
//因为当 a*x + b*y != N * gcd(a,b)时，一定无解
//整数与 0 的最大公约数就是这个整数本身
//由裴蜀定理可知：对于a,b，一定存在非零整数 x，y 使得 a*x + b*y = gcd(a,b),其中x,y是能取到的最小值(因为 a*x + b*y = n*gcd(a,b) )
// a*x + b*y = gcd(a,b) = gcd(b, a % b), 则 b*y + x*(a - (a / b)下取整 * b) = gcd(b, a % b) = gcd(a,b)
//可得： a*x + b*(y - a / b * x) = gcd(a,b)
// a*x + b*y = d 的所有通解为：x = x0 - b / d * k;  y = y0 + b / d * k      (k取整数)
//通解由式子 a * (x - b / d) + b * (y + a / d) = d  推得     (乘法分配一下即可将括号内的加数和减数均消掉)
#include <iostream>

using namespace std;

int exgcd(int a,int b,int &x,int &y)//最终得到的 x 即为 a 模 b 的乘法逆元
{
    if (!b)//如果是 a % 0,则可得出：a*1 + 0*y == a
    {
        x = 1,y = 0;
        return a;
    }
    int d = exgcd(b,a % b,y,x);
    y -= a / b * x;
    return d;
}

int main()
{
    int n;
    cin >> n;
    while(n --)
    {
        int a,b,x,y;
        cin >> a >> b;
        exgcd(a,b,x,y);
        cout << x << ' ' << y << endl;
    }
    return 0;
}