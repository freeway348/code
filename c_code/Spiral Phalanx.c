#include <stdio.h>
#include <stdlib.h>
#define MAX 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void circle(int m,/*起始行*/int n,/*起始列*/int k/*k阶*/,int array[MAX][MAX])
{
	int i;
	for (i=0;i<k;i++)//→
	{
		array[m][n+i]=array[m][n+i-1]+1;
	} 
	for(i=1;i<k;i++)//↓ 
	{
		array[m+i][n+k-1]=array[m+i-1][n+k-1]+1;
	}
	for(i=1;i<k;i++)//← 
	{
		array[m+k-1][n+k-i-1]=array[m+k-1][n+k-i]+1;
	}
	for(i=1;i<k-1;i++)//↑
	{
		array[m+k-1-i][n]=array[m+k-i][n]+1;
	 } 
}

int main(int argc, char *argv[]) {
	int n,array[MAX][MAX]={0};
	int i,j;
	scanf("%d",&n);
	array[0][0]=1;
	for (i=1;i<n;i++)//→
	{
		array[0][i]=array[0][i-1]+1;
	} 
	for(i=1;i<n;i++)//↓ 
	{
		array[i][n-1]=array[i-1][n-1]+1;
	}
	for(i=1;i<n;i++)//← 
	{
		array[n-1][n-i-1]=array[n-1][n-i]+1;
	}
	for(i=1;i<n-1;i++)//↑
	{
		array[n-1-i][0]=array[n-i][0]+1;
	 } 
	for (i=1;i<(n+1)/2;i++)
	{
		circle(i,i,n-2*i,array);
	}
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			printf("%d ",array[i][j]);		
		}
		printf("\n");
	}
	return 0;
}
