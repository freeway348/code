#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b;
	int m;
	int count=0;
	printf("请输入要求最大公约数的两数:\n");
	scanf("%d%d",&a,&b);//required a>b;
	m=a%b;
	while (m != 0 )
	{
		a=b;
		b=m;
		m=a%b;
		count++;
	}
	printf("最大公约数为%d\n",b);
	printf("程序运行的时间复杂度为O(%d)",count);
	return 0;
}
