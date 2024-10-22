#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	struct prisoner
	{
		int f;//是否是计数的人,0：非，1：是 
		int tl;//是否开过灯，开过为1，没开过为0 
	}p[100]={0,0,0};
	int turn_off=0;//计数人的关灯次数（不计第一天 
	int light;//灯初始未知，0为关，1为开 
	srand((unsigned)time(NULL));
	int num=0,day=0;
	light=rand()%2;//0为关，1为开 
	num=rand()%100;
	p[num].f=1;
	printf("第%d号囚犯是计数人\n",num);
	while (turn_off < 198)//未知灯的初始状态，若灯初始为开，则98人均开灯两次后，总次数为197次，第198次必是第99人 
	{
		if (p[num].f==0 && p[num].tl<2)
		{
			if (light == 0) 
			{
				printf("%d号囚犯开灯\n",num);
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
	printf("花费的时间是%d天",day);//因为每天只有一个人能出来放风，所以每个人的放风次数总和就是天数。 
	return 0;
}
