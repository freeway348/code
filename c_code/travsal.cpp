#include <stdio.h>
#include <stdlib.h>
#define MAXV 100
#define INF 32767
#include MAX 100
typedef struct ANode
{
	int adjvex;					//�붥��i���ڵĶ����ţ���һ���߽�㣩 
	struct ANode *nextarc;		//ָ����һ���߽�� 
	int weight;					//Ȩֵ 
}ArcNode;			  			//�߽�� 
typedef struct Vnode
{
	int data;					//��data��ͷ��� 
	ArcNode *firstarc;			//ָ����ͷ������ڵĵ�һ���߽�� 
}VNode;							//ͷ��� (���洢�߶�Ӧ��Ȩֵ)
typedef struct
{
	VNode adjlist[MAXV];		//�ڽӱ���MAX+1��ͷ���
	int n,e;					//ͼ�еĶ�����n�ͱ���e 
}AdjGraph;						//�������ڽӱ� 
void CreateAdj(AdjGraph *&G,int A[MAXV][MAXV],int n,int e)  //����ͼ���ڽӱ�
{
	int i,j;
	ArcNode *p;
	G=(AdjGraph *)malloc(sizeof(AdjGraph));
	for(i=0;i<n;i++)
		G->adjlist[i].firstarc=NULL;	//ͷ���Ϊ�� 
	for (i=0;i<n;i++)
	{
		for (j=n-1;j>=0;j--)
			if (A[i][j]!=0 && A[i][j]!=INF)
			{
				p=(AdjGraph *)malloc(sizeof(AdjGraph));
				p->adjvex=j;			//��� 
				p->weight=A[i][j];		//��Ȩֵ
				p->nextarc=G->adjlist[i].firstarc;  //ͷ�巨������p����������ҲΪ����˳��ȡ��
				G->adjlist[i].firstarc=p; 
			}
	}
	G->n=n;
	G->e=e;
 } 
 
void DispArc(AdjGraph *G,int n)
{
	int i;
	ArcNode *p;
	for (i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc;			//ָ���i��ͷ���ĵ�һ���߽�� 
		printf("%3d: ",i);
		while(p!=NULL)
		{
			printf("%3d[%d]",p->adjvex,p->weight);
			p=p->nextarc;
		} 
		printf("��\n");				//��ͷ��������еı߽��������� 
	}
}

void DestroyArc(AdjGraph *&G)
{
	int i;
	ArcNode *pre,*p;
	for (i=0;i<G->n;i++)
	{
		pre=G->adjlist[i].firstarc;
		if (pre!=NULL)			//ͷ��㲻Ϊ��ʱ
		{p=pre->nextarc;		//���ڽӵ���һ���߽�㸳ֵ��p 
			while (p!= NULL)	//��p��Ϊ�գ�������pre���������,��pΪ�գ��������pre�������һ��forѭ�� 
			{
				free(pre);
				pre=p;
				p=p->nextarc;
			}
		free(pre);
		}
	}
	free(G);
}

int visited[MAX]={0};
void DFS(AdjGraph *G,int v)   	//�ӵ�v���㿪ʼ������ȱ��� (�ݹ�)
{
	int i;
	ArcNode *p;
	visited[v]=1;
	printf("%d",v); 
	p=G->adjlist[i].firstarc;
	while (p!=NULL)
	{
		if (visited[p->adjvex]==0)
			DFS(G,p->adjvex);
		p=p->nextarc;
	}
 } 
