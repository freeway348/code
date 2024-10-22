#include <stdio.h>
#include <stdlib.h>
#define MAXV <最大顶点个数>
#define INF 32767 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef strcut ANode 
{
	int adjvex;
	struct ANode *nextarc;
	int weight;
} ArcNode;

typedef struct Vnode 
{
	InfoType info;
	ArcNode *firstarc;
} VNode;

typedef struct 
{
	VNode adjlist[MAXV];
	int n,e;
} AdjGraph;

void CreateAdj (AdjGraph *&G,int A[MAXV][MAXV],int n,int e)
{
	int i,j;
	ArcNode *p;
	G=(AdjGraph *)malloc(sizeof(AdjGraph));
	for (i=0;i<n;i++)
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<n;i++)
	{
		for (j=n-1;j>=0;j--)
		{
			if (A[i][j]!=0 && A[i][j]!=INF)
			{
				p=(ArcNode *)malloc(sizeof(ArcNode));
				p->adjvex=j;
				p->weight=A[i][j];
				p->nextarc=G->adjlist[i].firstarc;
				G->adjlist[i].firstarc=p;
			}
		}
	}
	G->n=n;
	G->e=e;
}

void DispAdj (AdjGraph *G)
{
	int i;
	ArcNode *p;
	for (i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc;
		printf("%3d:",i);
		while (p!=NULL)
		{
			printf("%3d[%d]→",p->adjvex,p->weight);
			p=p->nextarc;
		 } 
		 printf("∧\n");
	}
}

void DestroyAdj(AdjGraph *&G)
{
	int i;
	ArcNode *pre,*p;
	for (i=0;i<G->n;i++)
	{
		pre=G->adjlist[i].firstarc;
		if (pre != NULL)
		{
			p=pre->nextarc;
			while (p!=NULL)
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

int main(int argc, char *argv[]) {
	return 0;
}
