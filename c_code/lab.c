#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LinkNode;

void CreatListF(LinkNode *L,ElemType a[],int n){
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

int main(int argc, char *argv[]) {
	return 0;
}
