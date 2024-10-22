#include <stdio.h>
#include <stdlib.h>


int main()
{
	long long f[10010];
	int mo[30];
	int n,v;
 	scanf("%d%d",&v,&n);
 	for(int i=1;i<=v;++i)
 	{
    	 scanf("%d",&mo[i]);
 	}
 	f[0] = 1;
 	for(int i=1;i<=v;++i)
 	{
 	    for(int j=mo[i];j<=n;++j)
    	 {
        	 f[j] += f[j-mo[i]];
     	}
 	}
	 printf("%lld",f[n]);
	 return 0;
}
