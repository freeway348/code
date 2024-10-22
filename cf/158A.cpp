#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,k,i,num=0;
	int arr[100]={0};
	scanf("%d %d",&n,&k);
	for (i=0;i<n;i++)
		scanf ("%d",&arr[i]);
	for (i=0;i<k;i++)
		if (arr[i]>0)
			num++;	
	if (n>1)
	{
		for (int j=k;j<n;j++)
		if (arr[j]>0 && arr[j] == arr[j-1])
			num++;
		else 
			break;	
	}
	printf("%d",num);
	return 0;
}
