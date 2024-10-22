#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void quick_sort(int p[],int l,int r,int k)
{
	if (l >= r) return;
	int i=l - 1,j=r + 1,x=p[i + j >> 1];
	while (i < j)
	{
		while (p[++i] < x ) ;
		while (p[--j] > x ) ;
		if (i < j) 
		{
			int t = p[i];
			p[i] = p[j];
			p[j] = t;
		}
	}
	if (k<i) quick_sort(p,l,j,k);
	else if (k == i) 
	{
		printf("%d",p[k]);
		exit(0);
	}
	else if (k>i) quick_sort(p,j+1,r,k);
	
}

int main(int argc, char** argv) {
	int n,k;
	scanf("%d%d",&n,&k);
	int p[n];
	for (int i = 0 ; i < n ; i ++)
		scanf("%d",&p[i]);
	quick_sort(p,0,n-1,k);
	return 0;
}
