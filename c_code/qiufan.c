#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	struct prisoner
	{
		int f;//�Ƿ��Ǽ�������,0���ǣ�1���� 
		int tl;//�Ƿ񿪹��ƣ�����Ϊ1��û����Ϊ0 
	}p[100]={0,0,0};
	int turn_off=0;//�����˵Ĺصƴ��������Ƶ�һ�� 
	int light;//�Ƴ�ʼδ֪��0Ϊ�أ�1Ϊ�� 
	srand((unsigned)time(NULL));
	int num=0,day=0;
	light=rand()%2;//0Ϊ�أ�1Ϊ�� 
	num=rand()%100;
	p[num].f=1;
	printf("��%d�������Ǽ�����\n",num);
	while (turn_off < 198)//δ֪�Ƶĳ�ʼ״̬�����Ƴ�ʼΪ������98�˾��������κ��ܴ���Ϊ197�Σ���198�α��ǵ�99�� 
	{
		if (p[num].f==0 && p[num].tl<2)
		{
			if (light == 0) 
			{
				printf("%d����������\n",num);
				p[num].tl++;
				light=1;
				day++;
			}
			else if (light == 1)
			{
				day++;
			}
		 } 
		else if (p[num].f==0 && p[num].tl==2)
		{
			day++;
		}
		else if (p[num].f==1)
		{
			if (light == 1)
			{
				light=0;
				turn_off++;
				day++;
			}
			else if (light == 0)
			{
				day ++;
			}
		}
		num=rand()%100;
	}
	printf("���ѵ�ʱ����%d��",day);//��Ϊÿ��ֻ��һ�����ܳ����ŷ磬����ÿ���˵ķŷ�����ܺ;��������� 
	return 0;
}
