#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int player_complete=0;//游戏场次
int player_win=0; //胜场
int player_lose=0;//败场 
int player_draw=0;//平局 
//J:74		K:81		K:75
//如果成功取到牌，则return 0，如果随机取的牌在之前已经被取走了，则return 1。 
//可以在发牌的同时计算总值，把牌10单独列出来 

int fapai(int num,char p[100],int a[52],int *sum)
{z
	switch(num%4)
	{
		case 0:
			if (num/4==9)
			{
				if (a[num]!=0)
				{
					sprintf(p,"梅花10 ");
					a[num]--; 
					*sum+=10;
					return 0;
				}
				else 
				{
					return 1;
				}
			}
			else if (num/4<9 && num/4 >0) 
			{
				if (a[num]!=0)
				{
					sprintf(p,"梅花%d ",num/4+1);
					a[num]--;
					*sum+=num/4+1;
					return 0;
				}
				else 
				{
					return 1;
				}
			}
			else if (num/4==0)
			{
				if (a[num]!=0)
				{
					sprintf(p,"梅花A ");
					a[num]--;
					if(*sum+11>21)
						*sum+=1;
					else 
					{
						*sum+=11;
					}
					return 0;
				}
				else 
				{
					return 1;
				}
			}
			else if (num/4==10)
			{
				if (a[num]!=0)
				{
					sprintf(p,"梅花J "); 
					a[num]--;
					*sum+=11;
					return 0;
				}
				else 
				{
					return 1;
				}
			}
			else if (num/4==11)
			{
				if (a[num]!=0)
				{
					sprintf(p,"梅花Q "); 
					a[num]--;
					*sum+=12;
					return 0;
				}
				else 
				{
					return 1;
				}
			}
			else if (num/4==12)
			{
				if (a[num]!=0)
				{
					sprintf(p,"梅花K ");  
					a[num]--;
					*sum+=13;
					return 0;
				}
				else 
				{
					return 1;
				}
			}	
			break; 
		case 1:
			if (num/4==9)
			{
				if (a[num]!=0)
				{
					sprintf(p,"方块10 ");
					a[num]--;
					*sum+=10;
					return 0;
				}
				else 
				{
					return 1;
				}
			}
			else if (num/4<9 && num/4 >0) 
			{
				if (a[num]!=0)
				{
					sprintf(p,"方块%d ",num/4+1);
					a[num]--;
					*sum+=num/4+1;
					return 0;
				}
				else 
				{
					return 1;
				}
			}
			else if (num/4==0)
			{
				if (a[num]!=0)
				{
					sprintf(p,"方块A ");
					a[num]--;
					if(*sum+11>21)
						*sum+=1;
					else 
					{
						*sum+=11;
					}
					return 0;
				}
				else 
				{
					return 1;
				}
			}
			else if (num/4==10)
			{
				if (a[num]!=0)
				{
					sprintf(p,"方块J "); 
					a[num]--;
					*sum+=11;
					return 0;
				}
				else 
				{
					return 1;
				}
			}
			else if (num/4==11)
			{
				if (a[num]!=0)
				{
					sprintf(p,"方块Q "); 
					a[num]--;
					*sum+=12;
					return 0;
				}
				else 
				{
					return 1;
				}
			}
			else if (num/4==12)
			{
				if (a[num]!=0)
				{
					sprintf(p,"方块K ");  
					a[num]--;
					*sum+=13;
					return 0;
				}
				else 
				{
					return 1;
				}
			}	
			break;
		case 2:
			if (num/4==9)
			{
				if (a[num]!=0)
				{
					sprintf(p,"红桃10 ");
					a[num]--;
					*sum+=10;
					return 0;
				}
				else 
				{
					return 1;
				}
			}
			else if (num/4<9 && num/4 >0) 
			{
				if (a[num]!=0)
				{
					sprintf(p,"红桃%d ",num/4+1);
					a[num]--;
					*sum+=num/4+1;
					return 0;
				}
				else 
				{
					return 1;
				}
			}
			else if (num/4==0)
			{
				if (a[num]!=0)
				{
					sprintf(p,"红桃A ");
					a[num]--;
					if(*sum+11>21)
						*sum+=1;
					else 
					{
						*sum+=11;
					}
					return 0;
				}
				else 
				{
					return 1;
				}
			}
			else if (num/4==10)
			{
				if (a[num]!=0)
				{
					sprintf(p,"红桃J "); 
					a[num]--;
					*sum+=11;
					return 0;
				}
				else 
				{
					return 1;
				}
			}
			else if (num/4==11)
			{
				if (a[num]!=0)
				{
					sprintf(p,"红桃Q "); 
					a[num]--;
					*sum+=12;
					return 0;
				}
				else 
				{
					return 1;
				}
			}
			else if (num/4==12)
			{
				if (a[num]!=0)
				{
					sprintf(p,"红桃K ");  
					a[num]--;
					*sum+=13;
					return 0;
				}
				else 
				{
					return 1;
				}
			}	
			break; 
		default:
			if (num/4==9)
			{
				if (a[num]!=0)
				{
					sprintf(p,"黑桃10 ");
					a[num]--;
					*sum+=10;
					return 0;
				}
				else 
				{
					return 1;
				}
			}
			else if (num/4<9 && num/4 >0) 
			{
				if (a[num]!=0)
				{
					sprintf(p,"黑桃%d ",num/4+1);
					a[num]--;
					*sum+=num/4+1;
					return 0;
				}
				else 
				{
					return 1;
				}
			}
			else if (num/4==0)
			{
				if (a[num]!=0)
				{
					sprintf(p,"黑桃A ");
					a[num]--;
					if(*sum+11>21)
						*sum+=1;
					else 
					{
						*sum+=11;
					}
					return 0;
				}
				else 
				{
					return 1;
				}
			}
			else if (num/4==10)
			{
				if (a[num]!=0)
				{
					sprintf(p,"黑桃J "); 
					a[num]--;
					*sum+=11;
					return 0;
				}
				else 
				{
					return 1;
				}
			}
			else if (num/4==11)
			{
				if (a[num]!=0)
				{
					sprintf(p,"黑桃Q "); 
					a[num]--;
					*sum+=12;
					return 0;
				}
				else 
				{
					return 1;
				}
			}
			else if (num/4==12)
			{
				if (a[num]!=0)
				{
					sprintf(p,"黑桃K ");  
					a[num]--;
					*sum+=13;
					return 0;
				}
				else 
				{
					return 1;
				}
			}	 	
	}
}


//问题3：程序编译成功后运行，有时候可以正常运行，有时候运行无结果（卡死 
//已解决，问题是scanf输入的问题，需要在%c前加一个空格以吸收前一个scanf遗留下来的换行符或其他空格、\t等 
int main(int argc, char *argv[]) {
	int i,ch;
	int a[52];//从0到12对应牌的顺序为从A，2,3,4,5……到J,Q,K 
	//令花色按顺序分别为梅花、方块、红桃、黑桃 
	//开始洗牌 （随机发牌） 
	srand((unsigned)time(NULL));
	int num1=rand()%52;
	int num2=rand()%52;//取值范围是【0,51】  
	//printf("%d %d",num1,num2);
	int c=0,d=0,sum1=0,sum2=0;
	int *sum1_sample=&c,*sum2_sample=&d;
	char player_card[1000]="";
	char computer[1000]="";
	char op1[100]="";
	char op2[100]="";
	char bgn,rgm;//决定是否开始游戏/重新开始游戏 
	char choice;//玩家决定是否继续抽牌 
	int k;//电脑玩家决定是否继续抽牌 
	int n=0;//记录拿到第1张牌后电脑继续拿了几张牌 
	//开始游戏  
	loop: 
	printf("********************21点纸牌游戏*********************\n"); 
	printf("******************已进行游戏场次:%d*******************\n",player_complete);
	printf("******************胜利游戏场次:%d*********************\n",player_win);
	printf("******************失败游戏场次:%d*********************\n",player_lose);
	printf("******************平局游戏场次:%d*********************\n",player_draw);
	printf("\n");
	printf("******************是否开始游戏(y/n)******************\n"); 
	scanf(" %c",&bgn);
	while (bgn!='y' && bgn!='n')	
	{
		printf("输入有误，请重新输入\n");
		scanf(" %c",&bgn);
		while (getchar()!='\n')
			continue;
	}
	if (bgn == 'y')
	{
		player_complete++;
		system("cls");
	}
	else if (bgn == 'n')
	{
		exit(0);
	}
	//一次游戏结束后重新洗牌，即每种花色每张牌均存在 
	for (i=0;i<52;i++)//从A,2,3,4……到J,Q,K，每种牌均有四个花色，故数组元素即为52个，即52张牌 
		a[i]=1;
	//重置纸牌分值
	*sum1_sample=0;
	*sum2_sample=0;
	sum1=0;
	sum2=0; 
	//洗牌后发牌（随机发牌） 
	while (fapai(num1,op1,a,sum1_sample))//当fapai一直return 1,即一直抽到已被抽走的牌时，重新抽取 
	{
		//把未选到牌却加了值的总和去掉重复部分（已被抽走的牌的点数） 
		/*if (num/4==9)//10
			*sum1-=10;
		else if (num/4<9 && num/4 >0)//2-9
			*sum1-=num/4+1;
		else if (num/4==10)//J
			*sum1-=11;
		else if (num/4==11)//Q
			*sum1-=12;
		else if (num/4==12)//K
			*sum1-=13;
		else//A
		{
			if(*sum+11>21)//不好判断在fapai函数中执行的是+1还是+11，不如再定义一个备份的sum _sample
				*sum+=1;
			else 
			{
				*sum+=11;
			}
		}*/
		*sum1_sample=sum1;
		num1=rand()%52;
		fapai(num1,op1,a,sum1_sample);
	}
	sum1=*sum1_sample;
	while (fapai(num2,op2,a,sum2_sample)) 
	{
		*sum2_sample=sum2;
		num2=rand()%52;
		fapai(num2,op2,a,sum2_sample);
	}
	sum2=*sum2_sample;
	strcpy(player_card,op1);
	strcpy(computer,op2);
	printf("玩家的牌为%s	玩家的分数为%d\n",player_card,sum1);
	printf("电脑玩家的牌为%s	电脑玩家的分数为%d\n",computer,sum2);
	printf("\n");
	printf("*******************游戏进行中*******************\n");
	printf("\n");
	if (sum1>21 && sum2<21)
	{
		printf("\n");
		printf("**************人类玩家爆牌！**************\n");
		printf("**************电脑玩家获胜！**************\n");
		player_lose++;
		printf("\n");
		printf("请问是否继续游戏(y/n)\n"); 
		scanf(" %c",&rgm);
		while(rgm != 'y' && rgm != 'n') 
		{
			printf("**************输入错误！请重新输入**************\n"); 
			scanf(" %c",&rgm);
			while (getchar()!='\n')
				continue;
// while(getchar() != '\n')用于回收scanf()遗留在输入缓冲里包括回车符在内的遗留数据
//免得干扰下一个getchar()这类输入函数的功能
		}
		if (rgm=='y')
		{
			system("cls");
			goto loop;
		}
		else if (rgm=='n')
		{
			exit(0);
		}
	}
	else if (sum1<21 && sum2>21)
	{
		printf("\n");
		printf("**************电脑玩家爆牌！**************\n");
		printf("**************人类玩家获胜！**************\n");
		player_win++;
		printf("\n");
		printf("请问是否继续游戏(y/n)\n"); 
		scanf(" %c",&rgm);
		while(rgm != 'y' && rgm != 'n') 
		{
			printf("**************输入错误！请重新输入**************\n"); 
			scanf(" %c",&rgm);
			while (getchar()!='\n')
				continue;
		}
		if (rgm=='y')
		{
			system("cls");
			goto loop;
		}
		else if (rgm=='n')
		{
			exit(0);
		}
	}
	printf("玩家是否继续抽牌：y/n \n");
	scanf(" %c",&choice);//问题：该语句会被跳过并直接输出下面的“输入错误”语句---------解决：%c前加个空格 
	while(choice != 'y' && choice != 'n') 
	{
		printf("**************输入错误！请重新输入**************\n"); 
		scanf(" %c",&choice);
		while (getchar()!='\n')
			continue;
	}
	if (choice == 'n') 
	{
		printf("玩家的牌为%s	玩家的分数为%d\n",player_card,sum1);
		printf("电脑玩家的牌为%s	电脑玩家的分数为%d\n",computer,sum2);
		
	}
	if (choice == 'y')
	{
		while (1)
		{
			num1=rand()%52;
			while (fapai(num1,op1,a,sum1_sample))
			{
				*sum1_sample=sum1;
				num1=rand()%52;
				fapai(num1,op1,a,sum1_sample);
			}
			sum1=*sum1_sample;
			strcat(player_card,op1);
			printf("玩家的牌为%s	玩家的分数为%d\n",player_card,sum1);
			printf("电脑玩家的牌为%s	电脑玩家的分数为%d\n",computer,sum2);
			if (sum1>21)
			{
				printf("\n");
				printf("**************人类玩家爆牌！**************\n");
				printf("**************电脑玩家获胜！**************\n");
				player_lose++;
				printf("\n");
				printf("请问是否继续游戏(y/n)\n"); 
				scanf(" %c",&rgm);
				while(rgm != 'y' && rgm != 'n') 
				{
					printf("**************输入错误！请重新输入**************\n"); 
					scanf(" %c",&rgm);
					while (getchar()!='\n')
						continue;
				}
				if (rgm=='y')
				{
					system("cls");
					goto loop;
				}
				else if (rgm=='n')
				{
					exit(0);
				}
			}
			printf("玩家是否继续抽牌：y/n \n");
			scanf(" %c",&choice);
			printf("\n");
			while(choice != 'y' && choice != 'n')
			{
				printf("输入错误！请重新输入\n"); 
				scanf("%c",&choice);
				printf("\n");
				while (getchar()!='\n')
					continue;
			}
			if (choice=='n')
				break;
		 } 
	}
	
	k=(100*(21-sum2))/21+rand()%50;
	while (k>=50)//给电脑继续发牌 
	{
		printf("**************电脑玩家继续要牌**************\n");
		printf("**************电脑玩家游戏进行中**************\n");
		num2=rand()%52;
		while (fapai(num2,op2,a,sum2_sample))
		{
			*sum2_sample=sum2;
			num2=rand()%52;
			fapai(num2,op2,a,sum2_sample);
		}
		sum2=*sum2_sample;
		strcat(computer,op2);
		printf("玩家的牌为%s	玩家的分数为%d\n",player_card,sum1);
		printf("电脑玩家的牌为%s	电脑玩家的分数为%d\n",computer,sum2);
		if (sum2>21)
		{
			printf("\n");
			printf("**************电脑玩家爆牌！**************\n");
			printf("**************人类玩家获胜！**************\n");
			player_win++;
			printf("\n");
			printf("请问是否继续游戏(y/n)\n"); 
			scanf(" %c",&rgm);
			while(rgm != 'y' && rgm != 'n') 
			{
				printf("**************输入错误！请重新输入**************\n"); 
				scanf(" %c",&rgm);
				while (getchar()!='\n')
					continue;
			}
			if (rgm=='y')
			{
				system("cls");
				goto loop;
			}
			else if (rgm=='n')
			{
				exit(0);
			}
		}
		k=(100*(21-sum2))/21+rand()%50;
		n++;
		printf("\n");
		if (k<50)
		{
			printf("电脑玩家停止要牌\n");
			printf("玩家的牌为%s	玩家的分数为%d\n",player_card,sum1);
			printf("电脑玩家的牌为%s	电脑玩家的分数为%d\n",computer,sum2);
			break;
		}
	}
	if (n==0)
	{
		printf("\n");
		printf("电脑玩家放弃要牌\n");
		printf("玩家的牌为%s	玩家的分数为%d\n",player_card,sum1);
		printf("电脑玩家的牌为%s	电脑玩家的分数为%d\n",computer,sum2);
	}
	if (sum1>sum2)
	{
		printf("\n");
		printf("**************人类玩家获胜！**************\n");
		player_win++;
		printf("\n");
		printf("请问是否继续游戏(y/n)\n"); 
		scanf(" %c",&rgm);
		while(rgm != 'y' && rgm != 'n') 
		{
			printf("**************输入错误！请重新输入**************\n"); 
			scanf(" %c",&rgm);
			while (getchar()!='\n')
				continue;
		}
		if (rgm=='y')
		{
			system("cls");
			goto loop;
		}	
		else if (rgm=='n')
		{
			exit(0);
		}
	 } 
	 else if (sum1<sum2)
	 {
	 	printf("\n");
	 	printf("**************电脑玩家获胜！**************\n");
	 	player_lose++;
	 	printf("\n");
	 	printf("请问是否继续游戏(y/n)\n"); 
		scanf(" %c",&rgm);
		while(rgm != 'y' && rgm != 'n') 
		{
			printf("**************输入错误！请重新输入**************\n"); 
			scanf(" %c",&rgm);
			while (getchar()!='\n')
				continue;//清空行 
		}
		if (rgm=='y')
		{
			system("cls");
			goto loop;
		}
		else if (rgm=='n')
		{
			exit(0);
		}
	 }
	 else if (sum1==sum2)
	 {
	 	printf("\n");
	 	printf("******************平局！**************\n");
	 	player_draw++;
	 	printf("\n");
	 	printf("请问是否继续游戏(y/n)\n"); 
		scanf(" %c",&rgm);
		while(rgm != 'y' && rgm != 'n') 
		{
			printf("**************输入错误！请重新输入**************\n"); 
			scanf(" %c",&rgm);
			while (getchar()!='\n')
				continue;//清空行 
		}
		if (rgm=='y')
		{
			system("cls");
			goto loop;
		}
		else if (rgm=='n')
		{
			exit(0);
		}
	 }
	return 0;	
}
