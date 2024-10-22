#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int k,i=0;
	double sum;
	scanf("%d",&k);
	while (sum<=k)
	{
		i++;
		sum += (double)1/i;
	}
	printf("%d",i);
	return 0;
}
