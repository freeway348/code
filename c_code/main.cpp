#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 50
typedef struct student{
	int data;
	int class1;
	char *name=NULL;
	char *sex=NULL;
	char *major=NULL;
	char *academy=NULL;
}cl;
typedef struct{
	cl data[MaxSize];
	int length;
}SqList;

void CreateList(SqList *&L,cl std1,int n){//创建顺序表 
	int i=0,k=0;
	L=(SqList *)malloc(sizeof(SqList));
	while(i<n){
		L->data[k].data=std1.data;//序号 
		L->data[k].class1=std1.class1;//班级 
		L->data[k].name=std1.name;//姓名 
		L->data[k].sex=std1.sex;//性别 
		L->data[k].major=std1.major;//专业 
		L->data[k].academy=std1.academy;//学院 
		k++;i++;
	}
	L->length=k;
}

void InitList(SqList *&L){//初始化线性表 
	L=(SqList *)malloc(sizeof(SqList *));
	L->length=0;
}

void DestroyList(SqList *&L){//销毁线性表 
	free(L);
}

bool ListEmpty(SqList *L){//判断线性表是否为空表 
	return (L->length==0);
}

int ListLength(SqList *L){//求线性表的长度 
	return (L->length);
}

void DispList(SqList *L){//输出线性表
	for (int i=0;i<L->length;i++){
		printf("%d\t%s\t%s\t%s\t%s\t%s",L->data[i].data,L->data[i].name,L->data[i].sex,L->data[i].academy,L->data[i].major,L->data[i].class1);
	}
	printf("\n");
}

bool GetElem(SqList *L,int i,cl &std1){//按序号求线性表中的元素
	if(i<1 || i>L->length)
		return false;
	std1=L->data[i-1];
	return true;
}

int LocateElem(SqList *L,int e){//按元素查找
	int i=0;
	while(i<L->length && L->data[i].data!=e)
		i++;
	if (i>=L->length)
		return 0; 
	else
		return i+1;
}

bool ListInsert(SqList *&L,int i,cl std1){//插入数组元素
	int j;
	if(i<1 || i>L->length+1 || L->length==MaxSize)
		return false;
	i--;
	for(j=L->length;j>i;j--)
		L->data[j]=L->data[j-1];
	L->data[i]=std1;
	L->length++;
	return true;
}

bool ListDelete(SqList *&L,int i,cl &std1){//删除第i个数据元素
	int j;
	if(i<1 || i>L->length)
		return false;
	i--;
	std1=L->data[i];
	for(j=i;j<L->length-1;j++){
		L->data[j]=L->data[j+1];
								}
	L->length--;
}

int main(int argc, char *argv[]) {
	int i,n;
	cl stu1[MaxSize];
	SqList *sq=NULL;
	for (i=0;i<5;i++){
	scanf("%d%d %s %s %s %s",&stu1[i].data,&stu1[i].class1,stu1[i].name,stu1[i].sex,stu1[i].academy,stu1[i].major);}
	InitList(sq);
	scanf("%d",&n);
	CreateList(sq,stu1[i],n);
	ListEmpty(sq);
	ListLength(sq);
	DispList(sq);
	int e;
	scanf("%d",&e);
	LocateElem(sq,e);
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	ListInsert(sq,x,stu1[y]);
	DispList(sq);
	ListDelete(sq,z,stu1[i+2]);
	DispList(sq);
	return 0;
}
