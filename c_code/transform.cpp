/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LinkNode;

void CreatListF(LinkNode *&L,ElemType a[],int n){//头插法建立单链表 ,得到的就是与输入数字顺序相反的链表 
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
	while (p!=NULL/*L为头结点，L->next为首元结点*/){
		printf("%d",p->data);
		p=p->next;//转入下一个结点 
	}
	printf("\n");
} 

int mid1(LinkNode *L,int n/*长度*/){
	for (int i=0;i<n;i++){
		L=L->next;
		if (i==((n+1)/2-1)) return L->data;
	}	
}

void add_list(LinkNode *h1, LinkNode *h2, LinkNode *&h) // 指针的引用
{
    LinkNode *p1 = h1->next; // p1指向单链表h1中的第一个数据结点
    LinkNode *p2 = h2->next; // p2指向单链表h2中的第一个数据结点
    LinkNode *p, *r;
    int carry = 0;
    // 创建头结点
    h = (LinkNode *)malloc(sizeof(LinkNode));
    // r指向新创建头结点
    r = h;
    while(p1 != NULL && p2 != NULL)
    {
        // 创建新结点p
        p = (LinkNode *)malloc(sizeof(LinkNode));
        p->data = (p1->data + p2->data + carry) % 10; // 求余
        // 将新结点p插入到r指向的头结点之后
        r->next = p;
        // r后移一个结点
        r = p;
        carry = (p1->data + p2->data + carry) / 10; // 求商
        // p1和p2指向下一个结点
        p1 = p1->next;
        p2 = p2->next;
    }

    // 最后carry不为0时,创建一个结点存放它

    r->next = NULL;
}

int main(int argc, char *argv[]) {
	LinkNode *h,*g,*p;
	int n=10000,m;
	printf("请确定要输入的两个数字的位数");
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

