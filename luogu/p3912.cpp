#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
const int N = 1e8 + 10;
bool st[N];
int prime[N];
int cnt;

void is_prime(int x)
{
	for (int i = 2; i <= x; i ++)
	{
		if (!st[i])
		{
			prime[cnt++] = i;
			
			for (int j = 2 * i; j <= x; j += i)
				st[j] = true; // ·Ç ËØÊý
		}
	}
}

int main()
{
	cin >> n;
	is_prime(n);
	cout << cnt;

	return 0;
}
