//求 1 ~ n 有多少个质数
//时间复杂度为 O(nlglgn)
#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int prime[N], cnt;
bool st[N];

void is_prime(int n)
{
    for (int i = 2; i <= n; i ++)
    {
        if (!st[i])
        {
            prime[cnt ++] = i;
            for (int j = i + i; j <= n; j += i)
                st[j] = true;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    is_prime(n);
    cout << cnt << endl;
    return 0;
}