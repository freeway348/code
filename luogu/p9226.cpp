#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,k,num=0;
	scanf("%d%d",&n,&k);
	while ((n+num)%k!=0 || num == 0)
		num++;
	printf("%d",num);
	return 0;
}
