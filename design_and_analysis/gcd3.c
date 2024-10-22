#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b;
	int i;
	int count;
	printf("请输入要求最大公约数的两数:\n");
	scanf("%d%d",&a,&b);
	for (i=b;i>0;i--)
	{
		count ++ ; 
		if (a%i == 0 && b%i == 0)
		{
			printf("最大公约数为%d\n",i);
			break;
		}
	}
	printf("程序的时间复杂度为O(%d)",count);
	return 0;
}
