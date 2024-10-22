#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int num;
	int light;
	int tf=0,day=1;
	struct crime
	{
		int f;//确认计数人
		int ch;//开灯次数 
	}p[100]={{0,0}};
	srand((unsigned)time(NULL));
	num=rand()%100;
	p[num].f=1;
	light=rand()%2;
	printf("计数人是%d号囚犯\n",num);
	while (tf<99)
	{
		if (light==0)
		{
			if (p[num].f==0 && p[num].ch<2)
			{
				p[num].ch++;
				light=1;
				printf("第%d天第%d号囚犯开灯\n",day,num);
			}
			day++;
		}
		else if (light==1)
		{
			if (p[num].f==1)
			{
				tf++;
				light=0;
			}
			day++;
		}
		if (day%1000==0)
		{
			getchar();
		}
		num=rand()%100;
	}
	printf("确认所有人均放风过花费的时间为%d天\n",day-1);
	return 0;
}