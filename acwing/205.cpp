#include <iostream>
#include <cstring>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
void mul(int a[][2], int b[][2])//矩阵乘法 
{
	int c[2][2] = {0};
	for (int i = 0; i < 2; i ++)
		for (int j = 0; j < 2; j ++)
			for (int k = 0; k < 2; k ++)
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % 10000;
	memcpy(a, c, sizeof c);
}

int fin(int n)//矩阵快速幂 
{
	int a[2][2] = {0,1,0,0};
	int f[2][2] = {0,1,1,1};
	while (n)//快速幂 
	{
		if (n & 1) mul(a,f);
		mul(f,f);
		n >>= 1;
	}
	return a[0][0];
}

int main(int argc, char** argv) {
	int n;
	while(cin >> n, n != -1)
	{
		cout << fin(n) << '\n';		
	}
	return 0;
}
