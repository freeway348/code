#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int key,sum=0;
	while(scanf("%d",&key)==0)
	{
		printf("´íÎó£¬ÖØĞÂÊäÈë");
		scanf("%d",&key);
	}
	while (key>0)
	{
		sum=sum+key%10;
		key=key/10;
	}
	printf("%d",sum);
	return 0;
}
