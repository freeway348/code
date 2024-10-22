#include <iostream>
#include<algorithm>
typedef struct
{
	char data[5];	//���ֵ
	double weight;	//Ȩ��
	int parent;		//˫�׽��
	int lchild;		//���ӽ��
	int rchild;		//�Һ��ӽ��
} HTNode;

typedef struct
{
	char str[10];
	int num;
}HuffCode;

void createHuffman(HTNode ht[],int p)//htΪ��������ݣ�pΪ����� 
{
	double min1,min2=32767;
	int i,j,lnode=-1,rnode=-1;
	for (i=0;i<2*p-1;i++)
		ht[i].parent=ht[i].lchild=ht[i].rchild=-1;
	for (i=p;i<2*p-1;i++)
	{
		if (ht[i].parent==-1)	//ֻ����δ����������Ľڵ��в���
			{	if (ht[i].weight<min1)
				{	
					min2=min1;
					rnode=lnode;
					min1=ht[i].weight;
					lnode=i;
				}
				else if (ht[i].weight<min2)
				{
					min2=ht[i].weight;
					rnode=i;
				}
			}
		ht[lnode].parent = i;
		ht[rnode].parent = i;
		ht[i].weight = ht[lnode].weight+ht[rnode].weight;
		ht[i].lchild = lnode;
		ht[i].rchild = rnode;
	}
}
void huffmancode(HTNode ht[],HuffCode hcd[],int p)
{
	int i,c,f,j;
	for (i=0;i<p;i++)
	{
		c=i;
		f=ht[i].parent;//��f,c����ʾ��Ϊ�˲�����ԭ�������� 
		hcd[i].num=p;//�Ӻ���ǰ���룬�������ʱ��ǰ���󣬼�Ϊhuffmancode 
		while (ht[i].parent != -1 )//��������ֱ���ҵ�ͷ��� 
		{
			if (ht[f].lchild == c)
			{
				hcd[i].str[hcd[i].num--]='0';	
			}
			else if (ht[f].rchild == i)
			{
				hcd[i].str[hcd[i].num--]='1';
			}
			hcd[i].num++;//���huffmancode����ʼ�� 
			c=f;
			f=ht[f].parent;	
		}	
	}
	for (i=0;i<p;i++)
	{
		printf("��ĸ%s�Ĺ���������Ϊ��",ht[i].data);
		for (j=hcd[i].num;j<p;j++)
		{
			printf("%c",hcd[i].str[i]); 
		}
		printf("\n");
	}
}

int main(int argc, char** argv) {
	int i=0,j=0;
	int n;
	HTNode hft[100];//����Ƶ��/Ȩֵ 
	HuffCode hcd[100];
	//�������� 
	printf("��������ĸ����:\n");
	scanf(" %d",&n);
	for (i=0;i<n;i++)
		scanf (" %c",&hft[i].data);
	printf("��������ĸ�ֱ��Ӧ�ĳ��ִ���:\n");
	for (j=0;j<n;j++)
		scanf(" %d",&hft[j].weight);
	createHuffman(hft,i); 
	huffmancode(hft,hcd,i);
	return 0;
}
