//注意：费马小定理的前提条件是： p 必须为质数 ！！！！！！！
//mod 与 % 均表示模运算
//逆元：若 b 与 m 互质，且对于任意整数 a 均存在 b / a (b 能被 a 整除),如果存在一个数 x ，使得 a / b 同余 a * x (mod m) ，则称 x 为 b 模 m 的乘法逆元，记为b^(-1) (这里表示的不是b的-1次方，要区分开来)
//化简后（左右同乘 b）可得: b * x 同余 1 (mod m)

//如果 p 是质数， b * x 同余 1 (mod p)
//由费马小定理可得：b^(p - 1) 同余 1 (mod p), 故得知：b * b^(p - 2) 同余 1 (mod p)
//如果 b 是 p 的倍数，则一定无解，因为此时 b * x % p 的结果为 0 ，不满足费马小定理的条件
//记得要特判一下当 p - 2 == 0 的情况
//所以要求 a 模 p 的乘法逆元时，只要求 a^(p - 2)即可
#include <iostream>

using namespace std;
typedef long long LL;
//a^k % p
int qmi(int a,int k, int p)
{
	int res = 1;
	while(k)
	{
		if (k & 1) res = (LL) res * a % p;
		k >>= 1;
		a = (LL) a * a % p;
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	while(n --)
	{
		int a,p;//求 a 模 p 的乘法逆元
		scanf("%d%d",&a,&p);//输入输出较多时使用scanf和printf更快
        int res = qmi(a,p - 2,p);
		if (a % p) printf("%d\n",res);//当 a 不是 p 的倍数时才有解
         //特判考虑 p - 2 == 0 时的情况，此时qmi返回的一定是 1 ,所以不用 if (res) 来判断
        //用 if (res) 判断会出很大的问题，例如：若 a = 2, p = 2，则会输出res，这不符合条件，不可能有解，所以矛盾了
        //      但 a = 3, p = 2 时，仍会输出res，即：当 p == 2 时就会输出res，这就出问题了
        else cout << "impossible" << endl;
	}
	return 0;
}