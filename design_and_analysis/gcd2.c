#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b;
	int m;
	int count=0;
	printf("������Ҫ�����Լ��������:\n");
	scanf("%d%d",&a,&b);//required a>b;
	m=a%b;
	while (m != 0 )
	{
		a=b;
		b=m;
		m=a%b;
		count++;
	}
	printf("���Լ��Ϊ%d\n",b);
	printf("�������е�ʱ�临�Ӷ�ΪO(%d)",count);
	return 0;
}
