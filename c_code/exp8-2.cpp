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

//�ڽӱ�Ĵ��������������
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
      printf("��\n");   
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

void DFS(AdjGraph *G,int v)//������ȵݹ� 
 {	  
  ArcNode *p;	
  printf(" %d",v);//���ʶ���v
  visited[v]=1;//���ʺ���
  p=G->adjlist[v].firstarc;//pָ�򶥵�v����һ����ͷ���	
    while(p!=NULL)	
    {		
     if(visited[p->adjvex]==0)//��δ���ʹ�	
     DFS(G,p->adjvex);//��ݹ����	
     p=p->nextarc;//��������һ�����	
    }
 } 

 void DFS1(AdjGraph *G,int v)//������ȷǵݹ� 
 {   ArcNode *p;
     int St[MAX];//ջԪ�ش�ŵ�����
     int top=-1,x,w,i;	
     for(i=0;i<G->n;i++)
     visited[i]=0;//����ȫ����Ϊ0
     printf(" %d",v);//���ʶ���v
     visited[v]=1;//���ʺ���	
     top++;//topָ���һ
     St[top]=v;//v��ջ
     while(top>-1)
     {		
        x=St[top];//ȡ��x
        p=G->adjlist[x].firstarc;//pָ��x�����ڽ��	
        while(p!=NULL)//�ڶ���ѭ��		
        {			
            w=p->adjvex;//�����ڽ�㣬��ֵ����w	
            if(visited[w]==0)//δ���ʹ�	
            {			
 	         printf(" %d",w);//����		
 	         visited[w]=1;//���	
 	         top++;			
 	         St[top]=w;//��ջ		
 	         break;//ֱ���˳��ڶ���ѭ������ִ��p=p->nextarc	
 	      }			
             p=p->nextarc;//���򣨷��ʹ���������һ�����	
        }	
 	    	if(p==NULL)top--;	
    }  
 	 printf("\n");
}

 void BFS(AdjGraph *G,int v)//������� 
 {	ArcNode *p;	
    int queue[MAX],front=0,rear=0;//���ζ��У�����ʼ��
	int visited[MAX];//��Ŷ��������Ϣ������	
	int w,i;	
	for(i=0;i<G->n;i++)	
	 visited[i]=0;//����ȫ����Ϊ0	
	 printf(" %d",v);//���ʶ���v	
	 visited[v]=1;//���ʺ���	
	 rear=(rear+1)%MAX;//rear����
	 queue[rear]=v;//����v����
	     while(front!=rear)	
	     {		
	    front=(front+1)%MAX;//front����
	    w=queue[front];//����	
	        p=G->adjlist[w].firstarc;//pָ�����ڽ��	
	    while(p!=NULL)	
	        {			
	          if(visited[p->adjvex]==0)//δ���ʹ�����Ӹö�����������ڽ��
	          {		
	            printf(" %d",p->adjvex);//����	
		visited[p->adjvex]=1;//���ʺ���	
		rear=(rear+1)%MAX;//rear����
	        queue[rear]=p->adjvex;//����	
	           }			
	           p=p->nextarc;//����һ����㣬ֱ��->�ģ��˳��ڶ���ѭ��	
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
  printf("ͼG���ڽӱ�:\n");		
  DispAdj(G);		
  printf("�Ӷ���0��ʼ����������㷨���ݹ飩:\n");		
  DFS(G,0);		
  printf("\n");		
  printf("�Ӷ���0��ʼ����������㷨���ǵݹ飩:\n");		
  DFS1(G,0);		
  printf("�Ӷ���0��ʼ�Ĺ�������㷨���ǵݹ飩:\n");		
  BFS(G,0);		
  DestroyAdj(G);	
  return 1;
}

