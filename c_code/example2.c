#include <stdio.h>
#include <stdlib.h>
#define MAX 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i=0,j=0,count[26]={0};
	char str1[MAX]="",str2[MAX]="";
	scanf("%s",str1);
	scanf("%s",str2);
	while (str1[i]!='\0')
	{
		count[str1[i]-'a']=count[str1[i]-'a']+1;
		i++;
	}
	while (str2[j]!='\0')
	{
		count[str2[j]-'a']=count[str2[j]-'a']+1;
		j++;
	}
	for (i=0;i<26;i++)
	{
		if (count[i]!=0) printf("%c",i+'a');
	}
	return 0;
}
