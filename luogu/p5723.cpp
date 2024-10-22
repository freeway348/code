#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool fs (int m)
{
	if (m>=2)
	{
		for (int i=2;i<m;i++)
		{
			if (m%i == 0)
				return false;
		}	
		return true;
	}
}

int main(int argc, char** argv) {
	int L,k=0,sum=0;
	scanf("%d",&L);
	for (int i=2;i<L;i++)
	{
		if (fs(i))
		{
			if (sum+i>L)
				break;
			else 
			{
				sum += i;
				printf("%d\n",i);
				k++;
			}
		}
	}
	printf("%d",k);
	return 0;
}
