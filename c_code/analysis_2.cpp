#include <iostream>
#include<algorithm>
typedef struct
{
	char data[5];	//结点值
	double weight;	//权重
	int parent;		//双亲结点
	int lchild;		//左孩子结点
	int rchild;		//右孩子结点
} HTNode;

typedef struct
{
	char str[10];
	int num;
}HuffCode;

void createHuffman(HTNode ht[],int p)//ht为传入的数据，p为结点数 
{
	double min1,min2=32767;
	int i,j,lnode=-1,rnode=-1;
	for (i=0;i<2*p-1;i++)
		ht[i].parent=ht[i].lchild=ht[i].rchild=-1;
	for (i=p;i<2*p-1;i++)
	{
		if (ht[i].parent==-1)	//只在尚未构造二叉树的节点中查找
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
		f=ht[i].parent;//用f,c来表示是为了不打乱原哈夫曼树 
		hcd[i].num=p;//从后往前输入，最终输出时从前往后，即为huffmancode 
		while (ht[i].parent != -1 )//从下往上直至找到头结点 
		{
			if (ht[f].lchild == c)
			{
				hcd[i].str[hcd[i].num--]='0';	
			}
			else if (ht[f].rchild == i)
			{
				hcd[i].str[hcd[i].num--]='1';
			}
			hcd[i].num++;//输出huffmancode的起始点 
			c=f;
			f=ht[f].parent;	
		}	
	}
	for (i=0;i<p;i++)
	{
		printf("字母%s的哈夫曼编码为：",ht[i].data);
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
	HTNode hft[100];//出现频率/权值 
	HuffCode hcd[100];
	//输入数据 
	printf("请输入字母个数:\n");
	scanf(" %d",&n);
	for (i=0;i<n;i++)
		scanf (" %c",&hft[i].data);
	printf("请输入字母分别对应的出现次数:\n");
	for (j=0;j<n;j++)
		scanf(" %d",&hft[j].weight);
	createHuffman(hft,i); 
	huffmancode(hft,hcd,i);
	return 0;
}
