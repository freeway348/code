#include <iostream>
#include <algorithm>

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
            prime[cnt ++] = n;
            for (int j = i + i; j <= n; j += i)
                st[j] = true;
        }
    }
}

void dfs()
{
	
}

int main()
{


	return 0;
}