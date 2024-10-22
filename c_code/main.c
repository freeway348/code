#include<stdio.h>
#include<stdlib.h>
void sum1(int &a,int &b){
	a=a+b;
	b=2;
} 
void main(){
	int *p,*m;
	int f=6;
	p=&f;
	m=p;
	printf("%d,%d\n",*p,*m);
	*m=10;
	printf("%d,%d\n",*p,*m);
	*p=88;
	printf("%d,%d",*p,*m);
}
