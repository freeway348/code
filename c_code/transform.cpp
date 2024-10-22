/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LinkNode;

void CreatListF(LinkNode *&L,ElemType a[],int n){//ͷ�巨���������� ,�õ��ľ�������������˳���෴������ 
	LinkNode *s;
	L=(LinkNode *)malloc(sizeof(LinkNode));
	L->next=NULL;
	for (int i=0;i<n;i++){
		s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=a[i];
		s->next=L->next;
		L->next=s;
	}
}

void DispList(LinkNode *L){
	LinkNode *p=L->next;
	while (p!=NULL/*LΪͷ��㣬L->nextΪ��Ԫ���*/){
		printf("%d",p->data);
		p=p->next;//ת����һ����� 
	}
	printf("\n");
} 

int mid1(LinkNode *L,int n/*����*/){
	for (int i=0;i<n;i++){
		L=L->next;
		if (i==((n+1)/2-1)) return L->data;
	}	
}

void add_list(LinkNode *h1, LinkNode *h2, LinkNode *&h) // ָ�������
{
    LinkNode *p1 = h1->next; // p1ָ������h1�еĵ�һ�����ݽ��
    LinkNode *p2 = h2->next; // p2ָ������h2�еĵ�һ�����ݽ��
    LinkNode *p, *r;
    int carry = 0;
    // ����ͷ���
    h = (LinkNode *)malloc(sizeof(LinkNode));
    // rָ���´���ͷ���
    r = h;
    while(p1 != NULL && p2 != NULL)
    {
        // �����½��p
        p = (LinkNode *)malloc(sizeof(LinkNode));
        p->data = (p1->data + p2->data + carry) % 10; // ����
        // ���½��p���뵽rָ���ͷ���֮��
        r->next = p;
        // r����һ�����
        r = p;
        carry = (p1->data + p2->data + carry) / 10; // ����
        // p1��p2ָ����һ�����
        p1 = p1->next;
        p2 = p2->next;
    }

    // ���carry��Ϊ0ʱ,����һ���������

    r->next = NULL;
}

int main(int argc, char *argv[]) {
	LinkNode *h,*g,*p;
	int n=10000,m;
	printf("��ȷ��Ҫ������������ֵ�λ��");
	scanf("%d",&m);
	ElemType a[n]={0},b[n]={0};
	for (int j=0;j<m;j++){
		scanf("%d%d",&a[j],&b[j]);
	}
	CreatListF(h,a,m);
	DispList(h);
	CreatListF(g,b,m);
	DispList(g);//ok
	add_list(h,g,p);
	DispList(p);
	mid1(h,m);
	return 0;
}

