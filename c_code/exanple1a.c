#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,k=0,m,n;
	int ud,hd,td;
	if(scanf ("%d%d",&m,&n))
	{
		if (m<100) m=100;
		for (i=m;i<=n;i++)
		{
		if (i>=1000) break;
		ud=i%10;
		hd=(i%100)/10;
		td=i/100;
		if ((ud*ud*ud)+(hd*hd*hd)+(td*td*td)==i) 
			{
				printf("%d ",i);
				k++;
			}
		}
	}
	if (k==0) printf("No Answer");
	return 0;
}
