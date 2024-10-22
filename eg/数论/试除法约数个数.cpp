//求约数个数

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int get_divisors(int n)
{
    int res = 0;
    for (int i = 1; i <= n / i; i ++)
    {
        if (n % i == 0) 
        {
            res++;
            if (n / i != i) res++;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        int x;
        cin >> x;
        cout << get_divisors(x) << '\n';
    }
    
    return 0;
}