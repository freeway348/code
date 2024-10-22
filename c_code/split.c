#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,j,k,mid,sum=0,key,f=0;
	while(scanf("%d",&key)==0)
	{
		printf("输入错误，重新输入");
		scanf("%d",&key); 
	}
	mid=(key+1)/2;
	for (i=1;i<mid;i++)
	{
		for (j=i;j<=mid;j++)
		{
			sum=sum+j;
			if (sum==key)
			{
				for(k=i;k<=j;k++)
				{
					printf("%d ",k);
				}
				printf("\n");
				f=1;
				sum=0;
				break;
			}
			else if(sum>key) 
			{
				sum=0;
				break;
			}
		}
	}
	if(f==0) printf("NONE");
	return 0;
}
