#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b;
	clock_t start,end;
	double cpu_time;
	printf("������Ҫ�����Լ����������\n");
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
	printf("���Լ��Ϊ%d\n",a);
	end = clock();
	cpu_time= (double)(end - start)/CLOCKS_PER_SEC;
	printf("���������ʱ��Ϊ%lf��",cpu_time);
	return 0;
}
