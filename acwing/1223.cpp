#include <iostream>
#include <algorithm>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
typedef long long LL;
const int N = 110;
LL x[N],a[N],b[N];//a存分子，b存分母---------比值为 X(i - 1) / xi ，所以a存的是x(i - 1) 

LL gcd(LL a, LL b)
{
	return b ? gcd(b,a % b) : a;
}

LL gcd_sub(LL a, LL b)
{
	if (a < b) return gcd_sub(b,a);
	if (b == a) return a;
	return gcd_sub(b,a/b);
}

int main(int argc, char** argv) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> x[i];
	sort(x,x + n);
	int cnt = 0;
	for (int i = 1; i < n; i ++)
	{
		if (x[i - 1] != x[i])
		{
			LL d = gcd(x[i],x[0]);
			a[cnt] = x[i]/d;
			b[cnt] = x[0]/d;
			cnt ++;
		}
	}
	LL up = a[0],down = b[0];
	for (int i = 1; i < cnt; i ++)
	{
		up = gcd_sub(up,a[i]);
		down = gcd_sub(down,b[i]);
	}
	cout << up << '/' << down << endl;
	return 0;
}
