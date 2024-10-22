#include<stdio.h>
#include<stdlib.h>
#define maxsize 50

typedef struct{
	char data[maxsize];
	int length;	
}SqList;


void InitList(SqList *&L){//初始化顺序表 
	L=(SqList *)malloc(sizeof(SqList));
	L->length=0;
}


void CreateList(SqList *&L,char a[],int n){//向顺序表中依次插入元素
	int i=0,k=0;
	L=(SqList *)malloc(sizeof(SqList));
	while(i<n){
		L->data[k]=a[i];
		k++;i++;
	}
	L->length=k;
	
} 


void DispList(SqList *L){//输出顺序表L
	for(int i=0;i<L->length;i++){
		printf("%c \t",L->data[i]);
	}
	printf("\n");
} 


int ListLength(SqList *L){//输出顺序表的长度
	return(L->length);
}


bool ListEmpty(SqList *L){//判断表空
	return(L->length==0);
} 


bool GetElem(SqList *L,int i,char &e){//输出顺序表的第三个元素
	if(i<1||i>L->length) return false;
	e=L->data[i-1];
	return true;
} 


int LocateElem(SqList *L,char e){//输出元素a的位置
	int i=0;
	while(i<L->length && L->data[i]!=e)
		i++;
	if(i>L->length)
		return 0;
	else
		return i+1;
} 
 

bool ListInsert(SqList *&L,int i,char e){//在第四个元素位置上插入元素
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


bool ListDelete(SqList *&L,int i,char &e){//删除顺序表L的第三个元素
	int j;
	if(i<1||i>L->length)
		return false;
	i--;//使顺序表的物理序号与逻辑序号相一致 
	e=L->data[i];
	for(j=i;j<L->length-1;j++){	//依次向前移动元素 
		L->data[j]=L->data[j+1];}
	L->length--;
	return true;
} 


void DestroyList(SqList *&L){//销毁顺序表 
	free(L);
} 

int main(){
	SqList *L;
	printf(" 初始化顺序表L\n");
	InitList(L);
	printf("依次插入元素a,b,c,d,e五个元素\n");
	char a[5]={'a','b','c','d','e'};
	CreateList(L,a,5);
	printf("输出顺序表L:");
	DispList(L);
	printf("输出顺序表L的长度:");
	ListLength(L);
	printf("长度为：%d \n",ListLength(L));
	printf("判断L是否为空:");
	ListEmpty(L);
	if(ListEmpty(L))
		printf("表为空\n");
	else
		printf("表非空\n"); 
	printf("输出顺序表L的第三个元素:");
	char e;
	GetElem(L,3,e);
	printf("顺序表L的第三个元素为:%c \n",e); 
	printf("输出元素a的位置:");
	LocateElem(L,'a');
	printf("%d\n",LocateElem(L,'a'));
	printf("在第四个元素的位置上插入元素f \n");
	ListInsert(L,4,'f');
	printf("输出顺序表L:");
	DispList(L);
	printf("删除顺序表第三个元素:");
	ListDelete(L,3,e);
	printf("%c 被删除\n",e);
	printf("输出顺序表L:");
	DispList(L);
	printf("释放顺序表"); 
	DestroyList(L); 
	return(0);
} 

