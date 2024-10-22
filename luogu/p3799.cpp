//不在每次循环过程结束将ans与1e9+7取模（%）则会报错 
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int mod = 1e9 + 7;
int main(int argc, char** argv) {
	int n,p[100010]={0},x,max=0,ans=0,min=1e6;
	scanf("%d",&n);
	for (int i = 0;i < n; i ++)
	{
		scanf("%d",&x);
		++ p[x];
		//printf("%d",&p[x]);
		if (x > max) max = x; 
		if (x < min) min = x;
	}
	for (int i = min + 1;i <= max; i ++)
	{
		if (p[i] >= 2)
			for (int j = min; j <= i/2; j ++)
				if (p[j] && p[i - j])
				{
					if  (j != i - j)
						ans += (p[i]*(p[i] - 1)*p[i-j]*p[j])/2%mod;
					else if (p[j] >= 2)
						ans += (p[j]*(p[j] - 1)*p[i]*(p[i] - 1))/4 %mod;
				}	
		ans %= mod;//若放在外for循环外，则会wa大部分数据 
	}
	//ans %= mod; 
	printf("%d",ans);
	return 0;
}
