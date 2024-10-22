#include <iostream>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int qmi(int a, int b, int p)//计算 a 的 b 次幂，并将结果模 p 
{
	int res = 1 % p;//避免出题人出恶心数据，如：b = 0, p = 1，此时若不模p，则输出为1，正确输出应为0 
	while (b)
	{
		if (b & 1) res = (long long)res * a % p;
		a = (long long)a * a % p;
		b >>= 1;
	}
	return res;
}

int main(int argc, char** argv) {
	int n,m,k,x;
	cin >> n >> m >> k >> x;
	cout << ((x + (long long)qmi(10,k,n) * m) % n) << '\n';
	return 0;
}
