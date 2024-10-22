#include <iostream>
#include <stdlib.h>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef char ElemType;
typedef struct qnode{
	ElemType data;
	struct qnode *next;
}DataNode;

typedef struct {
	DataNode *front;//指向队头 
	DataNode *rear;//指向队尾 
}LinkQuNode;

void InitQueue(LinkQuNode *&q){
	q=(LinkQuNode *)malloc(sizeof(LinkQuNode));
	q->front=q->rear=NULL;
}

void DestroyQueue(LinkQuNode *&q)
{
	DataNode *pre=q->front,*p;
	if(pre !=NULL){
		p=pre->next;
		while(p!=NULL){
			free(pre);
			pre=p;p=p->next;
		}
		free(pre);
	}
	free(q);
}

bool QueueEmpty(LinkQuNode *q){
	return (q->rear==NULL);
}

bool enQueue(LinkQuNode *&q,ElemType e){
	DataNode *p;
	p=(DataNode *)malloc(sizeof(DataNode));
	p->data=e;
	p->next=NULL;
	if(q->rear==NULL) q->front=q->rear=p;
	else {
		q->rear->next=p;
		q->rear=p;
	}
	return true;
}

bool deQueue(LinkQuNode *&q,ElemType &e){
	DataNode *t;
	if(q->rear==NULL) return false;
	t=q->front;
	if(q->front==q->rear) q->front=q->rear=NULL;
	else q->front=q->front->next;
	e=t->data;
	free(t);
	return true;
}

int main(int argc, char** argv) {
	LinkQuNode *h;
	InitQueue(h);
	QueueEmpty(h);
	enQueue(h,'a');
	enQueue(h,'b');
	enQueue(h,'c');
	return 0;
}
