#include<stdio.h>
#include<stdlib.h>

typedef struct String {	//定义顺序串结构体
	char* data;		//数据指针
	int length;		//顺序串长度
}Str;

void StrAssign(Str&, char*);	//生成顺序串
int SubStr(Str, Str);			//BF算法
void GetNext(Str, int*&);		//求next数组
void GetNextval(Str, int*&);	//求nextval数组
int KMP(Str, Str, int*);		//KMP算法

int main(int argc, const char* argv[])
{
	char s[] = "abcabcdabcdeabcdefabcdefg";
	char t[] = "abcdeabcdefab";
	Str S, T;
	int i,idx;	//记录模式串在目标串中的位置
	int* next = NULL, * nextval = NULL; //next数组，nextval数组
	//建立目标串和模式串
	StrAssign(S, s);
	StrAssign(T, t);
	printf("简单匹配的结果：\n");
	idx = SubStr(S, T);
	if (idx != -1) {
		printf("匹配成功，位置为%d。\n", idx);
	}
	else {
		printf("匹配失败。\n");
	}
	GetNext(T, next);
	printf("next数组：\n");
	for (i = 0; i < T.length; i++) {
		printf("%d\t", next[i]);
	}
	printf("\n");
	GetNextval(T, nextval);
	printf("nextval数组：\n");
	for (i = 0; i < T.length; i++) {
		printf("%d\t", nextval[i]);
	}
	printf("\n");
	printf("使用KMP的结果（：\n");
	idx = KMP(S, T, next);
	if (idx != -1) {
		printf("匹配成功，位置为%d。\n", idx);
	}
	else {
		printf("匹配失败。\n");
	}
	printf("使用改进KMP的结果：\n");
	idx = KMP(S, T, nextval);
	if (idx != -1) {
		printf("匹配成功，位置为%d。\n", idx);
	}
	else {
		printf("匹配失败。\n");
	}
	return 0;
}
void StrAssign(Str& S, char* s)	//生成顺序串
{
	int i;
	for (i = 0; s[i] != '\0'; i++); //计算字符串长度
	S.length = i;	//顺序串长度
	S.data = s;		//顺序串内容
}
int SubStr(Str S, Str T) //BF算法
{
	int i, j;
	for (i = 0; i < S.length; i++) {
		for (j = 0; j < T.length; j++) {
			if (S.data[i + j] != T.data[j])
				break;	//当目标串与模式串不匹配时结束内循环，对下一个子串进行匹配
		}
		if (j >= T.length)	//当模式串全部扫描完成说明模式串已经找到了匹配的位置
			return (i+1);	//返回匹配的位置
	}
	return -1;
}
void GetNext(Str T, int*& next)
{
	int i, j;
	i = 0;
	j = -1;
	next = (int*)malloc(T.length * sizeof(int));
	while (next == NULL) {	
		next = (int*)malloc(T.length * sizeof(int));
	}
	next[0] = -1;
	while (i < T.length) {
		if (j == -1 || T.data[i] == T.data[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	}
}
void GetNextval(Str T, int*& nextval)
{
	int i, j;
	i = 0;
	j = -1;
	nextval = (int*)malloc(T.length * sizeof(int));
	while (nextval == NULL) {
		nextval = (int*)malloc(T.length * sizeof(int));
	}
	nextval[0] = -1;
	while (i < T.length) {
		if (j == -1 || T.data[i] == T.data[j]) {
			i++;
			j++;
			if (T.data[i] != T.data[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	}
}

int KMP(Str S, Str T, int* N)
{
	int i, j;
	i = j = 0;
	while (i < S.length && j < T.length) 
	{
		if (j == -1 || S.data[i] == T.data[j]) 
		{
			i++;
			j++;
		}
		else
			j = N[j];	//i不变，j后退
	}
	if (j >= T.length)
		return (i+1-T.length);	//返回匹配的位置
	else
		return -1;
}

