#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//本题要注意学号、总成绩与语文成绩的对应关系，交换过程中不能乱 
//使用结构体存储此类数据有奇效 
int main(int argc, char** argv) {
	int n,j=0,t;
	scanf("%d",&n);
	int p[3*n]={0};
	int sum[n]={0};
	int k[n];
	for (int i=0;i<3*n;i++)
	{
		scanf("%d",&p[i]);
	}
	while (j<n)
	{
		sum[j] = p[3*j]+p[3*j+1]+p[3*j+2];
		k[j]=j+1;
		j++;
	}
	for (int i=0;i<n;i++)
	{
		for (j=n-1;j>i;j--)
		{
			if (sum[j]==sum[j-1] && p[j*3]>p[j*3-3])
			{
				t=sum[j];
				sum[j]=sum[j-1];
				sum[j-1]=t;
				t=k[j];
				k[j]=k[j-1];
				k[j-1]=t;
				t=p[j*3];
				p[j*3]=p[j*3-3];
				p[j*3-3]=t;
			}
			else if (sum[j]==sum[j-1] && p[j*3]==p[j*3-3] && k[j]<k[j-1])
			{
				t=sum[j];
				sum[j]=sum[j-1];
				sum[j-1]=t;
				t=k[j];
				k[j]=k[j-1];
				k[j-1]=t;
				t=p[j*3];
				p[j*3]=p[j*3-3];
				p[j*3-3]=t;
			}
			else if (sum[j]>sum[j-1])
			{
				t=sum[j];
				sum[j]=sum[j-1];
				sum[j-1]=t;
				t=k[j];
				k[j]=k[j-1];
				k[j-1]=t;
				t=p[j*3];
				p[j*3]=p[j*3-3];
				p[j*3-3]=t;
			}
		}
	}
	for (int i=0;i<5;i++)
	{
		printf("%d %d\n",k[i],sum[i]);
	}
	return 0;
}
