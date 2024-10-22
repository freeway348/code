#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

int judge(long long a,long long b)
{
	if (a>b)
		return 1;
	else 
		return 0;
}

int main(int argc, char *argv[]) {
	char a[1000000000],b[1000000000];
	long long i,len,len1,len2,k=0;
	char sum[100000000000];
	scanf("%s",&a);
	scanf("%s",&b);
	len1=strlen(a);
	len2=strlen(b);
	if (judge(len1,len2)==1)
	{
		for (i=0;i<len1-len2;i++)
			sum[i]=a[i];
		
	}
	else 
	{
		
	}
	for (i=0;i<len;i++)
	{
		sum[i] = a[len1-i] + b[len2-i] - '0' + k;
		if (sum[i] > 57)
		{
			sum[i]-=10;
			k++;
		}
	}
	for (i=0;i<flen-len;i++)
	{
		
	}
	return 0;
}
