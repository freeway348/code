#include <iostream>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int qmi(int a, int b, int p)//���� a �� b ���ݣ��������ģ p 
{
	int res = 1 % p;//��������˳��������ݣ��磺b = 0, p = 1����ʱ����ģp�������Ϊ1����ȷ���ӦΪ0 
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
