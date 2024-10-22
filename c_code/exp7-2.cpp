#include "btree .cpp"

//先序遍歷
void PreOrder(BTNode *b)
 {
 	if (b!=NULL)
	 {
	 	printf("%c ",b->data);//輸出根節點 
	 	PreOrder(b->lchild);//遍歷左子樹
		PreOrder(b->rchild);//遍歷右子樹 
	 }
 }
 
//中序遍歷
void InOrder (BTNode *b)
{
	if (b!=NULL)
	{
		InOrder (b->lchild);
		printf("%c ",b->data);
		InOrder(b->rchild);
	}
 } 
 
//後序遍歷
void PostOrder(BTNode *b)
{
	if (b!=NULL)
	{
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		printf("%c ",b->data);
	}
 } 
 
//层次遍历算法
typedef struct 
{	BTNode *data[MaxSize];				//存放队中元素
	int front,rear;						//队头和队尾指针
} SqQueue;								//顺序队类型
void InitQueue(SqQueue *&q)				//初始化队列
{	q=(SqQueue *)malloc (sizeof(SqQueue));
	q->front=q->rear=0;
}
void DestroyQueue(SqQueue *&q)			//销毁队列
{
	free(q);
}
bool QueueEmpty(SqQueue *q)				//判断队列是否为空
{
	return(q->front==q->rear);
}
bool enQueue(SqQueue *&q,BTNode *e)		//进队列
{	if ((q->rear+1)%MaxSize==q->front)	//队满上溢出
		return false;
	q->rear=(q->rear+1)%MaxSize;
	q->data[q->rear]=e;
	return true;
}
int Count(SqQueue *&q)					//求队列中的元素个数 
{
	return (q->rear-q->front+MaxSize)%MaxSize;
}
bool deQueue(SqQueue *&q,BTNode *&e)	//出队列
{	if (q->front==q->rear)				//队空下溢出
		return false;
	q->front=(q->front+1)%MaxSize;
	e=q->data[q->front];
	return true;
}
//--------------------------------------------------------

//基本层次遍历算法
void LevelOrder(BTNode *b)			//基本层次遍历算法 
{
	BTNode *p;
	SqQueue *qu;
	InitQueue(qu);					//初始化队列
	enQueue(qu,b);					//根结点指针进入队列
	while (!QueueEmpty(qu))			//队不为空循环
	{
		deQueue(qu,p);				//出队结点p
		printf("%c ",p->data);		//访问结点p
		if (p->lchild!=NULL)		//有左孩子时将其进队
			enQueue(qu,p->lchild);
		if (p->rchild!=NULL)		//有右孩子时将其进队
			enQueue(qu,p->rchild);
	} 
}

//分层次的层次遍历算法
void LevelOrder1(BTNode *b)			//分层次的层次遍历算法 
{
	BTNode *p;
	SqQueue *qu;
	InitQueue(qu);					//初始化队列
	int curl=1;						//表示当前层次(初始化为1) 
	enQueue(qu,b);					//根结点指针进入队列
	while (!QueueEmpty(qu))			//队不为空循环
	{
		printf("第%d层: ",curl); 
		int cnt=Count(qu);		//求当前层次的结点个数
		for(int i=0;i<cnt;i++)		//循环cnt次访问当前层的全部结点 
		{ 
			deQueue(qu,p);				//出队结点p
			printf("%c ",p->data);		//访问结点p
			if (p->lchild!=NULL)		//有左孩子时将其进队
				enQueue(qu,p->lchild);
			if (p->rchild!=NULL)		//有右孩子时将其进队
				enQueue(qu,p->rchild);
		}
		curl++;
		printf("\n"); 
	} 
}

//先序、中序和后序非递归遍历算法
typedef struct 
{	BTNode *data[MaxSize];			//存放栈中的数据元素
	int top;						//存放栈顶指针，即栈顶元素在data数组中的下标
} SqStack;							//顺序栈类型

void InitStack(SqStack *&s)			//初始化栈
{	s=(SqStack *)malloc(sizeof(SqStack));//分配一个是顺序栈空间，首地址存放在s中
	s->top=-1;						//栈顶指针置为-1
}
void DestroyStack(SqStack *&s)		//销毁栈
{
	free(s);
}
bool StackEmpty(SqStack *s)			//判断栈是否为空
{
	return(s->top==-1);
}
bool Push(SqStack *&s,BTNode *e)	//进栈
{	if (s->top==MaxSize-1)			//栈满的情况，即栈上溢出
		return false;
	s->top++;						//栈顶指针增1
	s->data[s->top]=e;				//元素e放在栈顶指针处
	return true;
}
bool Pop(SqStack *&s,BTNode *&e)	//出栈
{	if (s->top==-1)					//栈为空的情况，即栈下溢出
		return false;
	e=s->data[s->top];				//取栈顶指针元素的元素
	s->top--;						//栈顶指针减1
	return true;
}
bool GetTop(SqStack *s,BTNode *&e)	//取栈顶元素
{	if (s->top==-1)					//栈为空的情况，即栈下溢出
		return false;
	e=s->data[s->top];				//取栈顶元素
	return true;
}

void PreOrder1(BTNode *b)			//先序非递归遍历算法1
{
	BTNode *p;
	SqStack *st;					//定义一个顺序栈指针st
	InitStack(st);					//初始化栈st
	Push(st,b);					//根节点进栈
	while (!StackEmpty(st))		//栈不为空时循环
	{
		Pop(st,p);				//退栈节点p并访问它
		printf("%c ",p->data);	//访问节点p
		if (p->rchild!=NULL)	//有右孩子时将其进栈
			Push(st,p->rchild);
		if (p->lchild!=NULL)	//有左孩子时将其进栈
			Push(st,p->lchild);
	}
	printf("\n");
	DestroyStack(st);				//销毁栈
}
void PreOrder2(BTNode *b)			//先序非递归遍历算法2
{
	BTNode *p;
	SqStack *st;					//定义一个顺序栈指针st
	InitStack(st);					//初始化栈st
	p=b;
	while (!StackEmpty(st) || p!=NULL)
	{
		while (p!=NULL)				//访问节点p及其所有左下节点并进栈
		{
			printf("%c ",p->data);	//访问节点p
			Push(st,p);				//节点p进栈
			p=p->lchild;			//移动到左孩子
		}
		if (!StackEmpty(st))		//若栈不空
		{
			Pop(st,p);				//出栈节点p
			p=p->rchild;			//转向处理其右子树
		}
	}
	printf("\n");
	DestroyStack(st);				//销毁栈
}

void InOrder1(BTNode *b)				//中序非递归遍历算法
{
	BTNode *p;
	SqStack *st;						//定义一个顺序栈指针st
	InitStack(st);						//初始化栈st
	if (b!=NULL)
	{
		p=b;
		while (!StackEmpty(st) || p!=NULL)
		{
			while (p!=NULL)				//扫描节点p的所有左下节点并进栈
			{
				Push(st,p);				//节点p进栈
				p=p->lchild;			//移动到左孩子
			}
			if (!StackEmpty(st))		//若栈不空
			{
				Pop(st,p);				//出栈节点p
				printf("%c ",p->data);	//访问节点p
				p=p->rchild;			//转向处理其右子树
			}
		}
		printf("\n");
	}
	DestroyStack(st);				//销毁栈
}

void PostOrder1(BTNode *b)				//后序非递归遍历算法
{
	BTNode *p,*r;
	bool flag;
	SqStack *st;						//定义一个顺序栈指针st
	InitStack(st);						//初始化栈st
	p=b;
	do
	{
		while (p!=NULL)					//扫描节点p的所有左下节点并进栈
		{
			Push(st,p);					//节点p进栈
			p=p->lchild;				//移动到左孩子
		}
		r=NULL;							//r指向刚刚访问的节点，初始时为空
		flag=true;						//flag为真表示正在处理栈顶节点
		while (!StackEmpty(st) && flag)
		{
			GetTop(st,p);				//取出当前的栈顶节点p
			if (p->rchild==r)			//若节点p的右孩子为空或者为刚刚访问过的节点	
			{
				printf("%c ",p->data);	//访问节点p
				Pop(st,p);
				r=p;					//r指向刚访问过的节点
			}
			else
			{	
				p=p->rchild;			//转向处理其右子树
				flag=false;				//表示当前不是处理栈顶节点
			}
		}
	} while (!StackEmpty(st));			//栈不空循环
	printf("\n");
	DestroyStack(st);				//销毁栈
}

int main()
{
	BTNode *b;
	char *str=(char *)"A(B(D,E(H(J,K(L,M(,N))),)),C(F,G(,I)))";
	CreateBTree(b,str);
	printf("b:");DispBTree(b);printf("\n");
	printf("先序遍历递归序列:");PreOrder(b);
	printf("\n");
	printf("中序遍历递归序列:");InOrder(b);
	printf("\n");
	printf("后序遍历递归序列:");PostOrder(b);
	printf("\n");
	printf("先序遍历非递归序列1:");PreOrder1(b);
	printf("先序遍历非递归序列2:");PreOrder2(b);
	printf("中序遍历非递归序列:");InOrder1(b);
	printf("后序遍历非递归序列:");PostOrder1(b);
	printf("基本层次遍历:");LevelOrder(b);
	printf("\n");
	printf("分层次的层次遍历:\n");LevelOrder1(b);
	DestroyBTree(b);
	return 0;
}
