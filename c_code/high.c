#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int m,i;
	float n,h,h1=0;
	scanf("%f%d",&n,&m);
	h=n;
	for (i=1;i<=m;i++)
	{
		h1=n/4;
		h=h+2*h1;
		n=n/4;
	}
	h=h-2*h1;
	printf("%.2f\n",h);
	printf("%.2f",h1);
	return 0;
}
