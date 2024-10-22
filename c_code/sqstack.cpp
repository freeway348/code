#include<stdio.h>
#include<stdlib.h>
#define maxsize 50

typedef struct{
	char data[maxsize];
	int length;	
}SqList;


void InitList(SqList *&L){//��ʼ��˳��� 
	L=(SqList *)malloc(sizeof(SqList));
	L->length=0;
}


void CreateList(SqList *&L,char a[],int n){//��˳��������β���Ԫ��
	int i=0,k=0;
	L=(SqList *)malloc(sizeof(SqList));
	while(i<n){
		L->data[k]=a[i];
		k++;i++;
	}
	L->length=k;
	
} 


void DispList(SqList *L){//���˳���L
	for(int i=0;i<L->length;i++){
		printf("%c \t",L->data[i]);
	}
	printf("\n");
} 


int ListLength(SqList *L){//���˳���ĳ���
	return(L->length);
}


bool ListEmpty(SqList *L){//�жϱ��
	return(L->length==0);
} 


bool GetElem(SqList *L,int i,char &e){//���˳���ĵ�����Ԫ��
	if(i<1||i>L->length) return false;
	e=L->data[i-1];
	return true;
} 


int LocateElem(SqList *L,char e){//���Ԫ��a��λ��
	int i=0;
	while(i<L->length && L->data[i]!=e)
		i++;
	if(i>L->length)
		return 0;
	else
		return i+1;
} 
 

bool ListInsert(SqList *&L,int i,char e){//�ڵ��ĸ�Ԫ��λ���ϲ���Ԫ��
	int j;
	if(i<1||i>L->length||L->length==maxsize)
		return false;
	i--;
	for(j=L->length;j>i;j--)
		L->data[j]=L->data[j-1];
	L->data[i]=e;
	L->length++;
	return true;
}


bool ListDelete(SqList *&L,int i,char &e){//ɾ��˳���L�ĵ�����Ԫ��
	int j;
	if(i<1||i>L->length)
		return false;
	i--;//ʹ˳��������������߼������һ�� 
	e=L->data[i];
	for(j=i;j<L->length-1;j++){	//������ǰ�ƶ�Ԫ�� 
		L->data[j]=L->data[j+1];}
	L->length--;
	return true;
} 


void DestroyList(SqList *&L){//����˳��� 
	free(L);
} 

int main(){
	SqList *L;
	printf(" ��ʼ��˳���L\n");
	InitList(L);
	printf("���β���Ԫ��a,b,c,d,e���Ԫ��\n");
	char a[5]={'a','b','c','d','e'};
	CreateList(L,a,5);
	printf("���˳���L:");
	DispList(L);
	printf("���˳���L�ĳ���:");
	ListLength(L);
	printf("����Ϊ��%d \n",ListLength(L));
	printf("�ж�L�Ƿ�Ϊ��:");
	ListEmpty(L);
	if(ListEmpty(L))
		printf("��Ϊ��\n");
	else
		printf("��ǿ�\n"); 
	printf("���˳���L�ĵ�����Ԫ��:");
	char e;
	GetElem(L,3,e);
	printf("˳���L�ĵ�����Ԫ��Ϊ:%c \n",e); 
	printf("���Ԫ��a��λ��:");
	LocateElem(L,'a');
	printf("%d\n",LocateElem(L,'a'));
	printf("�ڵ��ĸ�Ԫ�ص�λ���ϲ���Ԫ��f \n");
	ListInsert(L,4,'f');
	printf("���˳���L:");
	DispList(L);
	printf("ɾ��˳��������Ԫ��:");
	ListDelete(L,3,e);
	printf("%c ��ɾ��\n",e);
	printf("���˳���L:");
	DispList(L);
	printf("�ͷ�˳���"); 
	DestroyList(L); 
	return(0);
} 

