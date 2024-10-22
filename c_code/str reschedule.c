#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int pd(int a[],int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		if(a[i]!=0) return 0;
	}
	return 1;
}

int main(int argc, char *argv[]) {
	int i=0,j=0,a[MAX]={0},k;
	char str[MAX];
	while (scanf("%c",&str[i])!=EOF)
	{
		i++;
	}
	k=i;
	for(;j<i;j++)
	{
		if ('0'<=str[j] && str[j]<='9')
		{
			a[str[j]-'0']=a[str[j]-'0']+1;
		}
		else if ('a'<=str[j] && str[j]<='z')
		{
			a[str[j]-'0'-39]=a[str[j]-'0'-39]+1;
		}
	}
	while (pd(a,k)==0)
	{
		for (i=0;i<36;i++)
		{
			if (a[i]!=0)
			{
				if (i<10)
				{
				printf("%c",str[i+'0'+a[i]]-1);
				a[i]=a[i]-1;
				}
				else 
				{
				printf("%c",str[i+'0']);
				a[i]=a[i]-1;
				}
			}
		}
	}
	return 0;
}
