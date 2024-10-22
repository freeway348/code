#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int sum=0,a,b=0,n,i,j;
	scanf("%d%d",&a,&n);
	for (i=0;i<n;i++)
	{
		for (j=0;j<=i;j++)
		{
			b=b*10+a;
		}
		sum=sum+b;
		b=0;
	}
	printf("%d",sum);
	return 0;
}
