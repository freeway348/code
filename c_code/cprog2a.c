#include <stdio.h>
#include <stdlib.h>
#define MAX 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int m,n,a[MAX],b[MAX],c[MAX]={0},i,j,flag=0;
	char str;
	//printf("请输入第一组整数的个数");
	scanf("%d",&m);
	//printf("请输入第一组整数");
	for (i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
		str=getchar();
		if (str=='\n') break;
	}
	//printf("请输入第一组整数的个数");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
		str=getchar();
		if(str=='\n') break;
	}
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			if (a[i]==b[j])
			{
				flag=1;
				c[a[i]]=1;
			}
		}
	}
	for (i=0;i<m;i++)
	{
		if (c[a[i]]==1)
		{
			printf("%d ",a[i]);
			c[a[i]]=0;
		}
	}
	if (flag==0) printf("No Answer");
	return 0;
}
