#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int findsum(int in[], int len, int sum) //输入数组,数组长度,和 
{
    int i=0, j=len-1;
   	while (i<j)
    {
        if(in[i] + in[j] == sum)
        {
            printf("%d %d\n",in[i],in[j]);
            return 1;
        }
        else if(in[i] + in[j] < sum)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    printf("no answer");
    return 0;  
}

int main()
{
    int sum,i=0,a[MAX] = {0};
    char c;
   	for (i=0;i<1000;i++)
   	{
   		scanf ("%d",&a[i]);
		c=getchar();	
		if (c=='\n') break;
	}
	scanf("%d",&sum);
    findsum(a,i+1,sum);
    return 0;
}
