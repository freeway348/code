#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b;
	int i;
	int count;
	printf("������Ҫ�����Լ��������:\n");
	scanf("%d%d",&a,&b);
	for (i=b;i>0;i--)
	{
		count ++ ; 
		if (a%i == 0 && b%i == 0)
		{
			printf("���Լ��Ϊ%d\n",i);
			break;
		}
	}
	printf("�����ʱ�临�Ӷ�ΪO(%d)",count);
	return 0;
}
