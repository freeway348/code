#include<stdio.h>
#include<stdlib.h>

typedef struct String {	//����˳�򴮽ṹ��
	char* data;		//����ָ��
	int length;		//˳�򴮳���
}Str;

void StrAssign(Str&, char*);	//����˳��
int SubStr(Str, Str);			//BF�㷨
void GetNext(Str, int*&);		//��next����
void GetNextval(Str, int*&);	//��nextval����
int KMP(Str, Str, int*);		//KMP�㷨

int main(int argc, const char* argv[])
{
	char s[] = "abcabcdabcdeabcdefabcdefg";
	char t[] = "abcdeabcdefab";
	Str S, T;
	int i,idx;	//��¼ģʽ����Ŀ�괮�е�λ��
	int* next = NULL, * nextval = NULL; //next���飬nextval����
	//����Ŀ�괮��ģʽ��
	StrAssign(S, s);
	StrAssign(T, t);
	printf("��ƥ��Ľ����\n");
	idx = SubStr(S, T);
	if (idx != -1) {
		printf("ƥ��ɹ���λ��Ϊ%d��\n", idx);
	}
	else {
		printf("ƥ��ʧ�ܡ�\n");
	}
	GetNext(T, next);
	printf("next���飺\n");
	for (i = 0; i < T.length; i++) {
		printf("%d\t", next[i]);
	}
	printf("\n");
	GetNextval(T, nextval);
	printf("nextval���飺\n");
	for (i = 0; i < T.length; i++) {
		printf("%d\t", nextval[i]);
	}
	printf("\n");
	printf("ʹ��KMP�Ľ������\n");
	idx = KMP(S, T, next);
	if (idx != -1) {
		printf("ƥ��ɹ���λ��Ϊ%d��\n", idx);
	}
	else {
		printf("ƥ��ʧ�ܡ�\n");
	}
	printf("ʹ�øĽ�KMP�Ľ����\n");
	idx = KMP(S, T, nextval);
	if (idx != -1) {
		printf("ƥ��ɹ���λ��Ϊ%d��\n", idx);
	}
	else {
		printf("ƥ��ʧ�ܡ�\n");
	}
	return 0;
}
void StrAssign(Str& S, char* s)	//����˳��
{
	int i;
	for (i = 0; s[i] != '\0'; i++); //�����ַ�������
	S.length = i;	//˳�򴮳���
	S.data = s;		//˳������
}
int SubStr(Str S, Str T) //BF�㷨
{
	int i, j;
	for (i = 0; i < S.length; i++) {
		for (j = 0; j < T.length; j++) {
			if (S.data[i + j] != T.data[j])
				break;	//��Ŀ�괮��ģʽ����ƥ��ʱ������ѭ��������һ���Ӵ�����ƥ��
		}
		if (j >= T.length)	//��ģʽ��ȫ��ɨ�����˵��ģʽ���Ѿ��ҵ���ƥ���λ��
			return (i+1);	//����ƥ���λ��
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
			j = N[j];	//i���䣬j����
	}
	if (j >= T.length)
		return (i+1-T.length);	//����ƥ���λ��
	else
		return -1;
}

