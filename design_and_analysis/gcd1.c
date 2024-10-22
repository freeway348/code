#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b;
	clock_t start,end;
	double cpu_time;
	printf("请输入要求最大公约数的两数：\n");
	scanf("%d%d",&a,&b);
	start = clock();
	while (a != b)
	{
		if (a>b)
		{
			a=a-b;
		}
		else if (a<b)
		{
			b=b-a;
			}	
	}
	printf("最大公约数为%d\n",a);
	end = clock();
	cpu_time= (double)(end - start)/CLOCKS_PER_SEC;
	printf("程序的运行时间为%lf秒",cpu_time);
	return 0;
}
