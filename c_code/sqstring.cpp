#include <iostream>
#include <stdlib.h>
#include <srdio.h>
#define MaxSize 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct
{
	char data[MaxSize];
	int length;
}SqString; 

void StrAssign(SqString &s,char cstr[])
{
	int i;
	for (i=0;cstr[i]!='\0';i++){
		s.data[i]=cstr[i]''
	}
	s.length=i;
}

void DestroyStr(SqString &s){   } //因为是系统自动分配内存而不是指针malloc分配内存空间，所以系统会自动销毁串，故无操作代码

StrCopy(SqString &s,SqString t)
{
	int i;
	for (i=0;i<t.length;i++)
		s.data[i]=t.data[i];
	s.length=t.length;
}

bool StrEqual(SqString s,SqString t)
{
	bool same=true;
	if (s.length!=t.length) same=false;
	else for (int i=0;i<s.length;i++){
		if (s.data[i]!=t.data[i]) {
			same=false;
			break;  //减少不必要运行时间 
		}
	}
	return same;
}

int StrLength(SqString s)
{
//	int i;
//	for (i=0;s.data[i]!='\0';i++) ;
//	return i;
	return s.length;
}

SqString Concat(SqString s,SqString t)
{
	SqString str;
	str.length=s.length+t.length;
	for (i=0;i<s.length;i++)
		str.data[i]=s.data[i];
	for (i=0;i<t.length;i++)
		str.data[s.length+i]=t.data[i];
	return str;
}

SqString SubStr(SqString s,int i,int j)
{
	SqString str;
	str.length=0;
	int k;
	if (i<=0 || j<0 || i+j-1>s.length || i>s.length/*因为j=0时i-1可能等于s.length*/) return str;
	for (k=i-1;k<i+j-1;k++){
		str.data[k-i+1]=s.data[k];
		str.length++;
	}
	return str;
}

SqString InsStr(SqString s1,int i,SqString s2)
{
	int j;
	SqString str;
	str.length=0;
	if(i<=0 || i>s1.length+1) return str;
	for (j=0;j<i-1;j++) str.data[j]=s1.data[j];
	for (j=0;j<s2.length;j++) str.data[i+j-1]=s2.data[j];
	for (j=i-1;j<s1.length;j++) str.data[s2.length+j]=s1.data[j];
	str.length=s1.length+s2.length;
	return str;	
}

int Strcmp(SqString s,SqString t)
{
	int i,comlen;
	if(s.length<t.length) comlen=s.length;  //求s和t的共同长度
	else comlen=t.length; 
	for (i=0;i<comlen;i++)
		if (s.data[i]>t.data[i]) //共同长度逐个字符比较 
			return 1;
		else if (s.data[i]<t.data[i])
			return -1;
	if (s.length==t.length) return 0; //s==t
	else if (s.length>t.length) return 1; //s>t
	else return -1; //s<t
}



