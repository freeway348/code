#include<stdio.h>
#include<malloc.h>
#define INF 32767
#define MAX 100
int visited[MAX];
typedef struct Anode
{
  int adjvex;
  struct Anode *nextarc;	
  int weight;
  }ArcNode;

typedef struct Vnode
{	
  int count;	
  ArcNode *firstarc;
  }VNode;

typedef struct
{
  VNode adjlist[MAX];	
  int n,e; 
}AdjGraph;

//邻接表的创建，输出，销毁
void CreateAdj(AdjGraph *&G,int A[MAX][MAX],int n,int e)
{	
  int i,j;	
  ArcNode *p;
  G=(AdjGraph *)malloc(sizeof(AdjGraph));
  for(i=0;i<n;i++);
  G->adjlist[i].firstarc=NULL;
  for(i=0;i<n;i++)	 
     for(j=n-1;j>=0;j--)	
	if(A[i][j]!=0&&A[i][j]!=INF)
	{	
	  p=(ArcNode *)malloc(sizeof(ArcNode));
	  p->adjvex=j;				
	  p->weight=A[i][j];				
	  p->nextarc=G->adjlist[i].firstarc;				
	  G->adjlist[i].firstarc=p;			
	}			
	G->n=n;G->e=e;
}

void DispAdj(AdjGraph *G)
{
   ArcNode *p;   
   for(int i=0;i<G->n;i++)   
   {	   
      p=G->adjlist[i].firstarc;	   
      printf("%3d:",i);	   
      while(p!=NULL)	   
      {		   
          printf("%3d[%d]->",p->adjvex,p->weight);		   
          p=p->nextarc;	   
      }	   
      printf("∧\n");   
   }
}

void DestroyAdj(AdjGraph *&G)
 {	
    ArcNode *pre,*p;	
    for(int i=0;i<G->n;i++)	
    {		
       pre=G->adjlist[i].firstarc;		
       if(pre!=NULL)		
       {			
            p=pre->nextarc;			
            if(p!=NULL)			
            {			 
               free(pre);			 
               pre=p;p=p->nextarc;			
             }			
           free(pre);		
        }
   }	
     free(G);
}

void DFS(AdjGraph *G,int v)//深度优先递归 
 {	  
  ArcNode *p;	
  printf(" %d",v);//访问顶点v
  visited[v]=1;//访问后标记
  p=G->adjlist[v].firstarc;//p指向顶点v的下一个弧头结点	
    while(p!=NULL)	
    {		
     if(visited[p->adjvex]==0)//若未访问过	
     DFS(G,p->adjvex);//则递归访问	
     p=p->nextarc;//否则找下一个结点	
    }
 } 

 void DFS1(AdjGraph *G,int v)//深度优先非递归 
 {   ArcNode *p;
     int St[MAX];//栈元素存放的数组
     int top=-1,x,w,i;	
     for(i=0;i<G->n;i++)
     visited[i]=0;//顶点全部置为0
     printf(" %d",v);//访问顶点v
     visited[v]=1;//访问后标记	
     top++;//top指针加一
     St[top]=v;//v进栈
     while(top>-1)
     {		
        x=St[top];//取出x
        p=G->adjlist[x].firstarc;//p指向x的相邻结点	
        while(p!=NULL)//第二重循环		
        {			
            w=p->adjvex;//有相邻结点，将值赋给w	
            if(visited[w]==0)//未访问过	
            {			
 	         printf(" %d",w);//访问		
 	         visited[w]=1;//标记	
 	         top++;			
 	         St[top]=w;//进栈		
 	         break;//直接退出第二重循环，不执行p=p->nextarc	
 	      }			
             p=p->nextarc;//否则（访问过），找下一个结点	
        }	
 	    	if(p==NULL)top--;	
    }  
 	 printf("\n");
}

 void BFS(AdjGraph *G,int v)//广度优先 
 {	ArcNode *p;	
    int queue[MAX],front=0,rear=0;//环形队列，并初始化
	int visited[MAX];//存放顶点访问信息的数组	
	int w,i;	
	for(i=0;i<G->n;i++)	
	 visited[i]=0;//顶点全部置为0	
	 printf(" %d",v);//访问顶点v	
	 visited[v]=1;//访问后标记	
	 rear=(rear+1)%MAX;//rear增加
	 queue[rear]=v;//顶点v进队
	     while(front!=rear)	
	     {		
	    front=(front+1)%MAX;//front增加
	    w=queue[front];//出队	
	        p=G->adjlist[w].firstarc;//p指向相邻结点	
	    while(p!=NULL)	
	        {			
	          if(visited[p->adjvex]==0)//未访问过，添加该顶点的所有相邻结点
	          {		
	            printf(" %d",p->adjvex);//访问	
		visited[p->adjvex]=1;//访问后标记	
		rear=(rear+1)%MAX;//rear增加
	        queue[rear]=p->adjvex;//进队	
	           }			
	           p=p->nextarc;//找下一个结点，直到->∧，退出第二重循环	
	        }
	     }	
	printf("\n");
}

int main()
{	
  AdjGraph *G;	
  int A[MAX][MAX]={		
      {0,5,INF,7,INF,INF},{INF,0,4,INF,INF,INF},		
      {8,INF,0,INF,INF,9},{INF,INF,5,0,INF,6},		
      {INF,INF,INF,5,0,INF},{3,INF,INF,INF,1,0}};		
  int n=6,e=10;		
  CreateAdj(G,A,n,e);		
  printf("图G的邻接表:\n");		
  DispAdj(G);		
  printf("从顶点0开始的深度优先算法（递归）:\n");		
  DFS(G,0);		
  printf("\n");		
  printf("从顶点0开始的深度优先算法（非递归）:\n");		
  DFS1(G,0);		
  printf("从顶点0开始的广度优先算法（非递归）:\n");		
  BFS(G,0);		
  DestroyAdj(G);	
  return 1;
}

