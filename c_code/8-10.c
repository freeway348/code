#include <stdio.h>
#include <stdlib.h>
#define MAX 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int m,k=0,a[MAX]={0};
	while(m<0 || scanf("%d",&m)==0)
	{
		printf("´íÎó£¬ÖØÐÂÊäÈë");
		scanf("%d",&m);
	}
	
	while(m>0)
	{
		a[k++]=m%8;
		m=m/8;
	}
	k=k-1;
	while (k>=0)
	{
		printf("%d",a[k--]);
	}
	return 0;
}
