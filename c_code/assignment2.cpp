#include<stdio.h>
#include<malloc.h>
 
typedef char ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LinkNode;

void CreatListR(LinkNode *&L, ElemType a[], int n)
{
	LinkNode *s, *r;
	L = (LinkNode *)malloc(sizeof(LinkNode));
	r = L;
	for (int i = 0;i < n;i++)
	{
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

void resultlist(LinkNode *L, LinkNode *&L1, LinkNode *&L2, LinkNode *&L3)
{
	LinkNode *p = L->next, *a, *b, *c,*m,*n,*q;
	L1 = (LinkNode *)malloc(sizeof(LinkNode));
	L2 = (LinkNode *)malloc(sizeof(LinkNode));
	L3 = (LinkNode *)malloc(sizeof(LinkNode));
	a = L1;
	b = L2;
	c = L3;
	while (p != NULL)
	{
		if (p->data >= '0' && p->data <= '9')
		{
			m = (LinkNode *)malloc(sizeof(LinkNode));
			m->data = p->data;
			a->next = m;
			a = m;
		}
		else if (p->data >= 'a' &&p->data <= 'z')
		{
			n = (LinkNode *)malloc(sizeof(LinkNode));
			n->data = p->data;
			b->next = n;
			b = n;
		}
		else if (p->data >= 'A' &&p->data <= 'Z')
		{
			q = (LinkNode *)malloc(sizeof(LinkNode));
			q->data = p->data;
			c->next = q;
			c = q;
		}
		else
		{	printf("´íÎó");
		}
		p = p->next;
	}
	a->next = NULL;
	b->next = NULL;
	c->next = NULL;
}

void DispList1(LinkNode *L)
{
	LinkNode *p = L->next;
	while (p != NULL)
	{
		printf(" %c ", p->data);
		p = p->next;
	}
	printf("\n");
}
 
void DestroyList(LinkNode*L)
{
	LinkNode*pre = L, *p = L->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;;
	}
	free(pre);
}

int main()
{
	LinkNode*L, *L1, *L2, *L3;
 char a[]={'a','b','c','2','F','C','D','5','2','m'};
  CreatListR(L,a,10);
  resultlist(L,L1,L2, L3);
  DispList1(L);
  DispList1(L1);
  DispList1(L2);
  DispList1(L3);
  DestroyList(L);
  DestroyList(L1);
  DestroyList(L2);
  DestroyList(L3);
 return 0;
}
