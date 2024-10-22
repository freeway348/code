#include <stdio.h>
#include <stdlib.h>
#define MAX 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void cover(int a, int n, int k)

{

    int i, j, t;

    for (i = 0; i < k; i++)

    {

         t = a[0];

         for (j = 1; j < n; j++)

             a[j - 1] = a[j];        //前一项覆盖后一项

         a[n - 1] = t;

    }

}

int main()
{
   int i,p,n,a[MAX]={0};
   scanf("%d%d",&p,&n);
   getchar();
	i=0;
	while (scanf("%d ",&a[i])!=EOF)
	{
		i++;
	}
	cover(a,n,p);
	for (i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
    return 0;
}


