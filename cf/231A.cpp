#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,i=0,j=0,num=0,sum = 0;
	int arr[3001];
	scanf (" %d",&n);
	for (i=0;i<n;i++)
		for (j=0;j<3;j++)
			scanf (" %d",&arr[i*3+j]);
	for (j = 0;j<n;j++)
	{
		for (int k = 0;k < 3;k++)
		{
			num += arr[j*3+k];
		}
		if (num > 1) 
		{
			sum++;
			num = 0;
		}
		else 
		{
			num=0;
		}		
	}
	printf("%d",sum);
	return 0;
}
