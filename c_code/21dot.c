#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int player_complete=0;//��Ϸ����
int player_win=0; //ʤ��
int player_lose=0;//�ܳ� 
int player_draw=0;//ƽ�� 
//J:74		K:81		K:75
//����ɹ�ȡ���ƣ���return 0��������ȡ������֮ǰ�Ѿ���ȡ���ˣ���return 1�� 
//�����ڷ��Ƶ�ͬʱ������ֵ������10�����г��� 

int fapai(int num,char p[100],int a[52],int *sum)
{z
	switch(num%4)
	{
		case 0:
			if (num/4==9)
			{
				if (a[num]!=0)
				{
					sprintf(p,"÷��10 ");
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
					sprintf(p,"÷��%d ",num/4+1);
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
					sprintf(p,"÷��A ");
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
					sprintf(p,"÷��J "); 
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
					sprintf(p,"÷��Q "); 
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
					sprintf(p,"÷��K ");  
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
					sprintf(p,"����10 ");
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
					sprintf(p,"����%d ",num/4+1);
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
					sprintf(p,"����A ");
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
					sprintf(p,"����J "); 
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
					sprintf(p,"����Q "); 
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
					sprintf(p,"����K ");  
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
					sprintf(p,"����10 ");
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
					sprintf(p,"����%d ",num/4+1);
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
					sprintf(p,"����A ");
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
					sprintf(p,"����J "); 
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
					sprintf(p,"����Q "); 
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
					sprintf(p,"����K ");  
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
					sprintf(p,"����10 ");
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
					sprintf(p,"����%d ",num/4+1);
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
					sprintf(p,"����A ");
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
					sprintf(p,"����J "); 
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
					sprintf(p,"����Q "); 
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
					sprintf(p,"����K ");  
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


//����3���������ɹ������У���ʱ������������У���ʱ�������޽�������� 
//�ѽ����������scanf��������⣬��Ҫ��%cǰ��һ���ո�������ǰһ��scanf���������Ļ��з��������ո�\t�� 
int main(int argc, char *argv[]) {
	int i,ch;
	int a[52];//��0��12��Ӧ�Ƶ�˳��Ϊ��A��2,3,4,5������J,Q,K 
	//�ɫ��˳��ֱ�Ϊ÷�������顢���ҡ����� 
	//��ʼϴ�� ��������ƣ� 
	srand((unsigned)time(NULL));
	int num1=rand()%52;
	int num2=rand()%52;//ȡֵ��Χ�ǡ�0,51��  
	//printf("%d %d",num1,num2);
	int c=0,d=0,sum1=0,sum2=0;
	int *sum1_sample=&c,*sum2_sample=&d;
	char player_card[1000]="";
	char computer[1000]="";
	char op1[100]="";
	char op2[100]="";
	char bgn,rgm;//�����Ƿ�ʼ��Ϸ/���¿�ʼ��Ϸ 
	char choice;//��Ҿ����Ƿ�������� 
	int k;//������Ҿ����Ƿ�������� 
	int n=0;//��¼�õ���1���ƺ���Լ������˼����� 
	//��ʼ��Ϸ  
	loop: 
	printf("********************21��ֽ����Ϸ*********************\n"); 
	printf("******************�ѽ�����Ϸ����:%d*******************\n",player_complete);
	printf("******************ʤ����Ϸ����:%d*********************\n",player_win);
	printf("******************ʧ����Ϸ����:%d*********************\n",player_lose);
	printf("******************ƽ����Ϸ����:%d*********************\n",player_draw);
	printf("\n");
	printf("******************�Ƿ�ʼ��Ϸ(y/n)******************\n"); 
	scanf(" %c",&bgn);
	while (bgn!='y' && bgn!='n')	
	{
		printf("������������������\n");
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
	//һ����Ϸ����������ϴ�ƣ���ÿ�ֻ�ɫÿ���ƾ����� 
	for (i=0;i<52;i++)//��A,2,3,4������J,Q,K��ÿ���ƾ����ĸ���ɫ��������Ԫ�ؼ�Ϊ52������52���� 
		a[i]=1;
	//����ֽ�Ʒ�ֵ
	*sum1_sample=0;
	*sum2_sample=0;
	sum1=0;
	sum2=0; 
	//ϴ�ƺ��ƣ�������ƣ� 
	while (fapai(num1,op1,a,sum1_sample))//��fapaiһֱreturn 1,��һֱ�鵽�ѱ����ߵ���ʱ�����³�ȡ 
	{
		//��δѡ����ȴ����ֵ���ܺ�ȥ���ظ����֣��ѱ����ߵ��Ƶĵ����� 
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
			if(*sum+11>21)//�����ж���fapai������ִ�е���+1����+11�������ٶ���һ�����ݵ�sum _sample
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
	printf("��ҵ���Ϊ%s	��ҵķ���Ϊ%d\n",player_card,sum1);
	printf("������ҵ���Ϊ%s	������ҵķ���Ϊ%d\n",computer,sum2);
	printf("\n");
	printf("*******************��Ϸ������*******************\n");
	printf("\n");
	if (sum1>21 && sum2<21)
	{
		printf("\n");
		printf("**************������ұ��ƣ�**************\n");
		printf("**************������һ�ʤ��**************\n");
		player_lose++;
		printf("\n");
		printf("�����Ƿ������Ϸ(y/n)\n"); 
		scanf(" %c",&rgm);
		while(rgm != 'y' && rgm != 'n') 
		{
			printf("**************�����������������**************\n"); 
			scanf(" %c",&rgm);
			while (getchar()!='\n')
				continue;
// while(getchar() != '\n')���ڻ���scanf()���������뻺��������س������ڵ���������
//��ø�����һ��getchar()�������뺯���Ĺ���
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
		printf("**************������ұ��ƣ�**************\n");
		printf("**************������һ�ʤ��**************\n");
		player_win++;
		printf("\n");
		printf("�����Ƿ������Ϸ(y/n)\n"); 
		scanf(" %c",&rgm);
		while(rgm != 'y' && rgm != 'n') 
		{
			printf("**************�����������������**************\n"); 
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
	printf("����Ƿ�������ƣ�y/n \n");
	scanf(" %c",&choice);//���⣺�����ᱻ������ֱ���������ġ�����������---------�����%cǰ�Ӹ��ո� 
	while(choice != 'y' && choice != 'n') 
	{
		printf("**************�����������������**************\n"); 
		scanf(" %c",&choice);
		while (getchar()!='\n')
			continue;
	}
	if (choice == 'n') 
	{
		printf("��ҵ���Ϊ%s	��ҵķ���Ϊ%d\n",player_card,sum1);
		printf("������ҵ���Ϊ%s	������ҵķ���Ϊ%d\n",computer,sum2);
		
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
			printf("��ҵ���Ϊ%s	��ҵķ���Ϊ%d\n",player_card,sum1);
			printf("������ҵ���Ϊ%s	������ҵķ���Ϊ%d\n",computer,sum2);
			if (sum1>21)
			{
				printf("\n");
				printf("**************������ұ��ƣ�**************\n");
				printf("**************������һ�ʤ��**************\n");
				player_lose++;
				printf("\n");
				printf("�����Ƿ������Ϸ(y/n)\n"); 
				scanf(" %c",&rgm);
				while(rgm != 'y' && rgm != 'n') 
				{
					printf("**************�����������������**************\n"); 
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
			printf("����Ƿ�������ƣ�y/n \n");
			scanf(" %c",&choice);
			printf("\n");
			while(choice != 'y' && choice != 'n')
			{
				printf("�����������������\n"); 
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
	while (k>=50)//�����Լ������� 
	{
		printf("**************������Ҽ���Ҫ��**************\n");
		printf("**************���������Ϸ������**************\n");
		num2=rand()%52;
		while (fapai(num2,op2,a,sum2_sample))
		{
			*sum2_sample=sum2;
			num2=rand()%52;
			fapai(num2,op2,a,sum2_sample);
		}
		sum2=*sum2_sample;
		strcat(computer,op2);
		printf("��ҵ���Ϊ%s	��ҵķ���Ϊ%d\n",player_card,sum1);
		printf("������ҵ���Ϊ%s	������ҵķ���Ϊ%d\n",computer,sum2);
		if (sum2>21)
		{
			printf("\n");
			printf("**************������ұ��ƣ�**************\n");
			printf("**************������һ�ʤ��**************\n");
			player_win++;
			printf("\n");
			printf("�����Ƿ������Ϸ(y/n)\n"); 
			scanf(" %c",&rgm);
			while(rgm != 'y' && rgm != 'n') 
			{
				printf("**************�����������������**************\n"); 
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
			printf("�������ֹͣҪ��\n");
			printf("��ҵ���Ϊ%s	��ҵķ���Ϊ%d\n",player_card,sum1);
			printf("������ҵ���Ϊ%s	������ҵķ���Ϊ%d\n",computer,sum2);
			break;
		}
	}
	if (n==0)
	{
		printf("\n");
		printf("������ҷ���Ҫ��\n");
		printf("��ҵ���Ϊ%s	��ҵķ���Ϊ%d\n",player_card,sum1);
		printf("������ҵ���Ϊ%s	������ҵķ���Ϊ%d\n",computer,sum2);
	}
	if (sum1>sum2)
	{
		printf("\n");
		printf("**************������һ�ʤ��**************\n");
		player_win++;
		printf("\n");
		printf("�����Ƿ������Ϸ(y/n)\n"); 
		scanf(" %c",&rgm);
		while(rgm != 'y' && rgm != 'n') 
		{
			printf("**************�����������������**************\n"); 
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
	 	printf("**************������һ�ʤ��**************\n");
	 	player_lose++;
	 	printf("\n");
	 	printf("�����Ƿ������Ϸ(y/n)\n"); 
		scanf(" %c",&rgm);
		while(rgm != 'y' && rgm != 'n') 
		{
			printf("**************�����������������**************\n"); 
			scanf(" %c",&rgm);
			while (getchar()!='\n')
				continue;//����� 
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
	 	printf("******************ƽ�֣�**************\n");
	 	player_draw++;
	 	printf("\n");
	 	printf("�����Ƿ������Ϸ(y/n)\n"); 
		scanf(" %c",&rgm);
		while(rgm != 'y' && rgm != 'n') 
		{
			printf("**************�����������������**************\n"); 
			scanf(" %c",&rgm);
			while (getchar()!='\n')
				continue;//����� 
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
