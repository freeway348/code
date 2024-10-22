#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int a[4]={0};
	int i,t;
	char p[4]="";
	for (i=0;i<3;i++)
	{
		scanf("%d",&a[i]);
	 }
	if (a[0]>a[1])
	{
		t = a[1];
		a[1] = a[0];
		a[0] = t;
	}
	if (a[0]>a[2])
	{
		t = a[2];
		a[2] = a[0];
		a[0] = t;
	}
	if (a[1]>a[2])
	{
		t = a[2];
		a[2] = a[1];
		a[1] = t;
	}
	scanf (" %s",p);
	printf("%d %d %d",a[p[0]-'A'],a[p[1]-'A'],a[p[2]-'A']);
	return 0;
}
