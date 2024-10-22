#include <iostream>
#include <algorithm>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
const int MOD = 998244353;
typedef long long LL;

LL qpow(LL a, LL b)
{
	LL res = 1;
	while(b)
	{
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	LL a,b;
	cin >> a >> b;
	if (a == 1)
	{
		cout << 0 << endl;
		return 0;
	 } 
	LL res = a, x = a;
	for (int i = 2; i * i <= x; i ++)//求欧拉函数
	{
		if (x % i == 0)
		{
			//欧拉函数中，求1~N与N的互质数个数，其中，N = p1^a1 * p2^a2 * ……pm^am 
			while (x % i == 0) x /= i; //找到因数pi,除尽 
			res = res / i * (i - 1); //欧拉函数中互质数个数为 res = N * ((p1 - 1)/p1)*((p2 - 1)/p2)*……*((pm - 1)/pm)   
		}
	} 
	if (x > 1) res = res / x * (x - 1);
	cout << res * qpow(a,b - 1) % MOD << endl;
	return 0;
}
