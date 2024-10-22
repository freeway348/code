#include <stdio.h>
#include <stdlib.h>
#define MAX 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int LWT[MAX]={0},LRT[MAX]={0},begin[MAX],end[MAX],t;
	int N,i,j,k=0,m1=0,m2=0;
	scanf("%d",&N);
	for (i=0;i<N;i++)
	{
		scanf("%d%d",&begin[i],&end[i]);
	}
	for (i=0;i<N;i++)
	{
		for (j=i+1;j<N;j++)
		{
			if (begin[i]>begin[j])
			{
				t=begin[i];
				begin[i]=begin[j];
				begin[j]=t;
				t=end[i];
				end[i]=end[j];
				end[j]=t;
			}
		}
	}
	LWT[m1]=end[k]-begin[k];
	for (j=1;j<N;j++)
	{
		if (end[j]>end[k] && begin[j]<=end[k])
		{
			LWT[m1]=LWT[m1]+end[j]-end[k];
			k=j;//记录结束时间最晚的人 
		}
		else if (begin[j]>end[k])
		{
			LWT[++m1]=end[j]-begin[j];
			LRT[m2++]=begin[j]-end[k];
			k=j; 
		}
	}
	for (i=1;i<m1;i++)
	{
		if (LWT[i]>LWT[0])
		{
			t=LWT[i];
			LWT[i]=LWT[0];
			LWT[0]=t;
		}
	}
	for (j=1;j<m2-1;j++)
	{
		if (LWT[i]>LWT[0])
		{
			t=LRT[i];
			LRT[i]=LRT[0];
			LRT[0]=t;
		}
	}
	printf("%d %d",LWT[0],LRT[0]);
	return 0;
}
