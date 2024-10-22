#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int k=0,i=0,len,t;
	char str[MAX]="",p;
	while (scanf("%c",&str[i])!=EOF)
	{
		i++;
	}
	len=strlen(str);
	for (i=0;i<len;i++)
	{
		if (str[i]==' ')
		{
			t=i-1;
			while (k<t)
			{
				p=str[k];
				str[k]=str[t];
				str[t]=p;
				k++;
				t--;
			}
			k=i+1;
		}
		if (i==len-1)
		{
			t=len-1;
			while (k<t)
			{
			p=str[k];
			str[k]=str[t];
			str[t]=p;
			k++;
			t--;
			}
		}
	}
	k=0;
	t=len-1;
	while (k<t)
	{
		p=str[k];
		str[k]=str[t];
		str[t]=p;
		k++;
		t--;	
	}
	puts(str);
	return 0;
}
