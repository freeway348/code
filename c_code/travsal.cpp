#include <stdio.h>
#include <stdlib.h>
#define MAXV 100
#define INF 32767
#include MAX 100
typedef struct ANode
{
	int adjvex;					//与顶点i相邻的顶点编号（第一个边结点） 
	struct ANode *nextarc;		//指向下一个边结点 
	int weight;					//权值 
}ArcNode;			  			//边结点 
typedef struct Vnode
{
	int data;					//第data个头结点 
	ArcNode *firstarc;			//指向与头结点相邻的第一个边结点 
}VNode;							//头结点 (不存储边对应的权值)
typedef struct
{
	VNode adjlist[MAXV];		//邻接表有MAX+1个头结点
	int n,e;					//图中的顶点数n和边数e 
}AdjGraph;						//完整的邻接表 
void CreateAdj(AdjGraph *&G,int A[MAXV][MAXV],int n,int e)  //创建图的邻接表
{
	int i,j;
	ArcNode *p;
	G=(AdjGraph *)malloc(sizeof(AdjGraph));
	for(i=0;i<n;i++)
		G->adjlist[i].firstarc=NULL;	//头结点为空 
	for (i=0;i<n;i++)
	{
		for (j=n-1;j>=0;j--)
			if (A[i][j]!=0 && A[i][j]!=INF)
			{
				p=(AdjGraph *)malloc(sizeof(AdjGraph));
				p->adjvex=j;			//编号 
				p->weight=A[i][j];		//赋权值
				p->nextarc=G->adjlist[i].firstarc;  //头插法插入结点p，即从左到右也为正常顺序取边
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
		p=G->adjlist[i].firstarc;			//指向第i个头结点的第一个边结点 
		printf("%3d: ",i);
		while(p!=NULL)
		{
			printf("%3d[%d]",p->adjvex,p->weight);
			p=p->nextarc;
		} 
		printf("∧\n");				//该头结点所在行的边结点均输出完毕 
	}
}

void DestroyArc(AdjGraph *&G)
{
	int i;
	ArcNode *pre,*p;
	for (i=0;i<G->n;i++)
	{
		pre=G->adjlist[i].firstarc;
		if (pre!=NULL)			//头结点不为空时
		{p=pre->nextarc;		//将邻接的下一个边结点赋值给p 
			while (p!= NULL)	//若p不为空，则销毁pre后继续往后,若p为空，则仅销毁pre后进入下一次for循环 
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
void DFS(AdjGraph *G,int v)   	//从第v个点开始深度优先遍历 (递归)
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
