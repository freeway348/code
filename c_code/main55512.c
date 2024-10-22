#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 50
typedef int ElemType;
typedef struct student{
	ElemType data;
	ElemType class1;
	char name[20];
	char sex[2];
	char major[20];
	char academy[20];
}stu;
typedef struct{
	stu dat[MaxSize];
	int length;
}SqList;

void CreateList(SqList *L,stu std1[],int n){//创建顺序表 
	int i=0,k=0;
	L=(SqList *)malloc(sizeof(SqList));
	while(i<n){
		L->dat[k].data=std1[i].data;//序号 
		L->dat[k].class1=std1[i].class1;//班级 
		strcpy(L->dat[k].name,std1[i].name);//姓名 
		strcpy(L->dat[k].sex,std1[i].sex);//性别 
		strcpy(L->dat[k].major,std1[i].major);//专业 
		strcpy(L->dat[k].academy,std1[i].academy);//学院 
		k++;
		i++;
	}
	L->length=k;
}

void InitList(SqList *L){//初始化线性表 
	L=(SqList *)malloc(sizeof(SqList));
	L->length=0;
}

void DestroyList(SqList *L){//销毁线性表 
	free(L);
}

void ListEmpty(SqList L){//判断线性表是否为空表 
	if(L.length==0) printf("true\n");
	else printf("false\n");
}

void ListLength(SqList L){//求线性表的长度 
	printf("%d\n",L.length);
}

void DispList(SqList L){//输出线性表
	int i;
	for (i=0;i<L.length;i++){
		printf("%d\t%s\t%s\t%s\t%s\t%d",L.dat[i].data,L.dat[i].name,L.dat[i].sex,L.dat[i].academy,L.dat[i].major,L.dat[i].class1);
	}
	printf("\n");
}

void GetElem(SqList *L,int i){//按序号求线性表中的元素
	if(i<1 || i>L->length)
		printf("false\n");
	printf("true\n");
}

int LocateElem(SqList L,ElemType e){//按元素查找
	int i=0;
	while(i<L.length && L.dat[i].data!=e)
		i++;
	if (i>=L.length)
		return 0; 
	else
		return i+1;
}

void ListInsert(SqList *L,int i,stu std1[],int k){//插入数组元素
	int j;
	if(i<1 || i>L->length+1 || L->length==MaxSize)
		printf("false\n");
	i--;
	for(j=L->length;j>i;j--)
		L->dat[j]=L->dat[j-1];
	L->dat[i]=std1[k];
	L->length++;
	printf("true\n");
}

void ListDelete(SqList *L,int i){//删除第i个数据元素
	int j;
	if(i<1 || i>L->length)
		printf("false\n");
	i--;
	for(j=i;j<L->length-1;j++){
		L->dat[j]=L->dat[j+1];
								}
	L->length--;
}

int main(int argc, char *argv[]) {
	int i;
	stu stu1[MaxSize];
	SqList sq;
	for (i=0;i<5;i++){
	scanf("%d%d %s %s %s %s",&stu1[i].data,&stu1[i].class1,stu1[i].name,stu1[i].sex,stu1[i].academy,stu1[i].major);}
	InitList(&sq);
	CreateList(&sq,stu1,5);
	ListEmpty(sq);
	ListLength(sq);
	DispList(sq);
	ElemType e;
	scanf("%d",&e);
	LocateElem(sq,e);
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	ListInsert(&sq,x,stu1,y);
	DispList(sq);
	ListDelete(&sq,z);
	DispList(sq);
	return 0;
}
