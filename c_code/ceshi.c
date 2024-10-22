#include <stdio.h>
#include <stdlib.h>
#include <string.h>
///* run this program using the console pauser or add your own getch, system("pause") or input loop */
///*void ceshi(char p[100])
//{
//	int i;
//	strcpy(p,"ajhku");		
//}*/
//
//int waysToStep(int n){
//    int i;
//    int dp[n+1];
//    dp[0]=0;
//    if (n==1)
//    {
//        return 1;
//    }
//    else if (n==2)
//    {
//        return 2;
//    }
//    else if (n==3)
//    {
//        return 4;
//    }
//    else 
//    {
//         for (i=4;i<=n;i++)
//        {
//            dp[i]=((dp[i-1]+dp[i-2])%1000000007+dp[i-3])%1000000007;
//        }
//    }
//    return dp[n];
//}
//
//int main(int argc, char *argv[]) {
//	int len,n;
//	scanf("%d",&n);
//	printf("\n");
//	len=waysToStep(n);
//	printf("%d\n",len);
//}
int main()
{
	int p[5]={1,4,27,8,0};
	int i;
	for (i=0;i<5;i++)
	{
		if (i==3) p[i]++;
		printf("%d\n",p[i]);
	}
	
	
	
	
	
	
	
	
	return 0;
}
