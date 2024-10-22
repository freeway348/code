#include <stdio.h>
#include <stdlib.h>
#define MAX 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int sum1=0,sum2=0,j,i,P[MAX],A[MAX],M,N;
	int t;
	scanf ("%d%d",&N,&M);
	for (i=0;i<M;i++)
	{
		scanf("%d%d",&P[i],&A[i]);
	}
	for (i=0;i<M;i++)
	{
		for (j=i+1;j<M;j++)
		{
			if (P[i]>P[j])
			{
				t=P[i];
				P[i]=P[j];
				P[j]=t;
				t=A[i];
				A[i]=A[j];
				A[j]=t;
			}
		}
	}
	for (i=0;i<M;i++)
	{
		sum1=sum1+P[i]*A[i];
		sum2=sum2+A[i];
		if (sum2>=N) 
			break;
	}
	sum1=sum1-(sum2-N)*P[i];
	printf("%d",sum1);
	return 0;
}
