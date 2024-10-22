#include "btree .cpp"

//�����v
void PreOrder(BTNode *b)
 {
 	if (b!=NULL)
	 {
	 	printf("%c ",b->data);//ݔ�������c 
	 	PreOrder(b->lchild);//��v���Ә�
		PreOrder(b->rchild);//��v���Ә� 
	 }
 }
 
//�����v
void InOrder (BTNode *b)
{
	if (b!=NULL)
	{
		InOrder (b->lchild);
		printf("%c ",b->data);
		InOrder(b->rchild);
	}
 } 
 
//�����v
void PostOrder(BTNode *b)
{
	if (b!=NULL)
	{
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		printf("%c ",b->data);
	}
 } 
 
//��α����㷨
typedef struct 
{	BTNode *data[MaxSize];				//��Ŷ���Ԫ��
	int front,rear;						//��ͷ�Ͷ�βָ��
} SqQueue;								//˳�������
void InitQueue(SqQueue *&q)				//��ʼ������
{	q=(SqQueue *)malloc (sizeof(SqQueue));
	q->front=q->rear=0;
}
void DestroyQueue(SqQueue *&q)			//���ٶ���
{
	free(q);
}
bool QueueEmpty(SqQueue *q)				//�ж϶����Ƿ�Ϊ��
{
	return(q->front==q->rear);
}
bool enQueue(SqQueue *&q,BTNode *e)		//������
{	if ((q->rear+1)%MaxSize==q->front)	//���������
		return false;
	q->rear=(q->rear+1)%MaxSize;
	q->data[q->rear]=e;
	return true;
}
int Count(SqQueue *&q)					//������е�Ԫ�ظ��� 
{
	return (q->rear-q->front+MaxSize)%MaxSize;
}
bool deQueue(SqQueue *&q,BTNode *&e)	//������
{	if (q->front==q->rear)				//�ӿ������
		return false;
	q->front=(q->front+1)%MaxSize;
	e=q->data[q->front];
	return true;
}
//--------------------------------------------------------

//������α����㷨
void LevelOrder(BTNode *b)			//������α����㷨 
{
	BTNode *p;
	SqQueue *qu;
	InitQueue(qu);					//��ʼ������
	enQueue(qu,b);					//�����ָ��������
	while (!QueueEmpty(qu))			//�Ӳ�Ϊ��ѭ��
	{
		deQueue(qu,p);				//���ӽ��p
		printf("%c ",p->data);		//���ʽ��p
		if (p->lchild!=NULL)		//������ʱ�������
			enQueue(qu,p->lchild);
		if (p->rchild!=NULL)		//���Һ���ʱ�������
			enQueue(qu,p->rchild);
	} 
}

//�ֲ�εĲ�α����㷨
void LevelOrder1(BTNode *b)			//�ֲ�εĲ�α����㷨 
{
	BTNode *p;
	SqQueue *qu;
	InitQueue(qu);					//��ʼ������
	int curl=1;						//��ʾ��ǰ���(��ʼ��Ϊ1) 
	enQueue(qu,b);					//�����ָ��������
	while (!QueueEmpty(qu))			//�Ӳ�Ϊ��ѭ��
	{
		printf("��%d��: ",curl); 
		int cnt=Count(qu);		//��ǰ��εĽ�����
		for(int i=0;i<cnt;i++)		//ѭ��cnt�η��ʵ�ǰ���ȫ����� 
		{ 
			deQueue(qu,p);				//���ӽ��p
			printf("%c ",p->data);		//���ʽ��p
			if (p->lchild!=NULL)		//������ʱ�������
				enQueue(qu,p->lchild);
			if (p->rchild!=NULL)		//���Һ���ʱ�������
				enQueue(qu,p->rchild);
		}
		curl++;
		printf("\n"); 
	} 
}

//��������ͺ���ǵݹ�����㷨
typedef struct 
{	BTNode *data[MaxSize];			//���ջ�е�����Ԫ��
	int top;						//���ջ��ָ�룬��ջ��Ԫ����data�����е��±�
} SqStack;							//˳��ջ����

void InitStack(SqStack *&s)			//��ʼ��ջ
{	s=(SqStack *)malloc(sizeof(SqStack));//����һ����˳��ջ�ռ䣬�׵�ַ�����s��
	s->top=-1;						//ջ��ָ����Ϊ-1
}
void DestroyStack(SqStack *&s)		//����ջ
{
	free(s);
}
bool StackEmpty(SqStack *s)			//�ж�ջ�Ƿ�Ϊ��
{
	return(s->top==-1);
}
bool Push(SqStack *&s,BTNode *e)	//��ջ
{	if (s->top==MaxSize-1)			//ջ�����������ջ�����
		return false;
	s->top++;						//ջ��ָ����1
	s->data[s->top]=e;				//Ԫ��e����ջ��ָ�봦
	return true;
}
bool Pop(SqStack *&s,BTNode *&e)	//��ջ
{	if (s->top==-1)					//ջΪ�յ��������ջ�����
		return false;
	e=s->data[s->top];				//ȡջ��ָ��Ԫ�ص�Ԫ��
	s->top--;						//ջ��ָ���1
	return true;
}
bool GetTop(SqStack *s,BTNode *&e)	//ȡջ��Ԫ��
{	if (s->top==-1)					//ջΪ�յ��������ջ�����
		return false;
	e=s->data[s->top];				//ȡջ��Ԫ��
	return true;
}

void PreOrder1(BTNode *b)			//����ǵݹ�����㷨1
{
	BTNode *p;
	SqStack *st;					//����һ��˳��ջָ��st
	InitStack(st);					//��ʼ��ջst
	Push(st,b);					//���ڵ��ջ
	while (!StackEmpty(st))		//ջ��Ϊ��ʱѭ��
	{
		Pop(st,p);				//��ջ�ڵ�p��������
		printf("%c ",p->data);	//���ʽڵ�p
		if (p->rchild!=NULL)	//���Һ���ʱ�����ջ
			Push(st,p->rchild);
		if (p->lchild!=NULL)	//������ʱ�����ջ
			Push(st,p->lchild);
	}
	printf("\n");
	DestroyStack(st);				//����ջ
}
void PreOrder2(BTNode *b)			//����ǵݹ�����㷨2
{
	BTNode *p;
	SqStack *st;					//����һ��˳��ջָ��st
	InitStack(st);					//��ʼ��ջst
	p=b;
	while (!StackEmpty(st) || p!=NULL)
	{
		while (p!=NULL)				//���ʽڵ�p�����������½ڵ㲢��ջ
		{
			printf("%c ",p->data);	//���ʽڵ�p
			Push(st,p);				//�ڵ�p��ջ
			p=p->lchild;			//�ƶ�������
		}
		if (!StackEmpty(st))		//��ջ����
		{
			Pop(st,p);				//��ջ�ڵ�p
			p=p->rchild;			//ת������������
		}
	}
	printf("\n");
	DestroyStack(st);				//����ջ
}

void InOrder1(BTNode *b)				//����ǵݹ�����㷨
{
	BTNode *p;
	SqStack *st;						//����һ��˳��ջָ��st
	InitStack(st);						//��ʼ��ջst
	if (b!=NULL)
	{
		p=b;
		while (!StackEmpty(st) || p!=NULL)
		{
			while (p!=NULL)				//ɨ��ڵ�p���������½ڵ㲢��ջ
			{
				Push(st,p);				//�ڵ�p��ջ
				p=p->lchild;			//�ƶ�������
			}
			if (!StackEmpty(st))		//��ջ����
			{
				Pop(st,p);				//��ջ�ڵ�p
				printf("%c ",p->data);	//���ʽڵ�p
				p=p->rchild;			//ת������������
			}
		}
		printf("\n");
	}
	DestroyStack(st);				//����ջ
}

void PostOrder1(BTNode *b)				//����ǵݹ�����㷨
{
	BTNode *p,*r;
	bool flag;
	SqStack *st;						//����һ��˳��ջָ��st
	InitStack(st);						//��ʼ��ջst
	p=b;
	do
	{
		while (p!=NULL)					//ɨ��ڵ�p���������½ڵ㲢��ջ
		{
			Push(st,p);					//�ڵ�p��ջ
			p=p->lchild;				//�ƶ�������
		}
		r=NULL;							//rָ��ոշ��ʵĽڵ㣬��ʼʱΪ��
		flag=true;						//flagΪ���ʾ���ڴ���ջ���ڵ�
		while (!StackEmpty(st) && flag)
		{
			GetTop(st,p);				//ȡ����ǰ��ջ���ڵ�p
			if (p->rchild==r)			//���ڵ�p���Һ���Ϊ�ջ���Ϊ�ոշ��ʹ��Ľڵ�	
			{
				printf("%c ",p->data);	//���ʽڵ�p
				Pop(st,p);
				r=p;					//rָ��շ��ʹ��Ľڵ�
			}
			else
			{	
				p=p->rchild;			//ת������������
				flag=false;				//��ʾ��ǰ���Ǵ���ջ���ڵ�
			}
		}
	} while (!StackEmpty(st));			//ջ����ѭ��
	printf("\n");
	DestroyStack(st);				//����ջ
}

int main()
{
	BTNode *b;
	char *str=(char *)"A(B(D,E(H(J,K(L,M(,N))),)),C(F,G(,I)))";
	CreateBTree(b,str);
	printf("b:");DispBTree(b);printf("\n");
	printf("��������ݹ�����:");PreOrder(b);
	printf("\n");
	printf("��������ݹ�����:");InOrder(b);
	printf("\n");
	printf("��������ݹ�����:");PostOrder(b);
	printf("\n");
	printf("��������ǵݹ�����1:");PreOrder1(b);
	printf("��������ǵݹ�����2:");PreOrder2(b);
	printf("��������ǵݹ�����:");InOrder1(b);
	printf("��������ǵݹ�����:");PostOrder1(b);
	printf("������α���:");LevelOrder(b);
	printf("\n");
	printf("�ֲ�εĲ�α���:\n");LevelOrder1(b);
	DestroyBTree(b);
	return 0;
}
