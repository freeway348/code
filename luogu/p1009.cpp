#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int fn(int n,int S[])
{
	int k,w,t;
	for (int i=1;i<=n;i++)
	{
		w=0; k=0;
		while (i!=0)
			{
				t = i%10;
				S[w] =	t + S[w] + k;
				k = (t+S[w])/10;//½øÎ» 
				if (k != 0)
					S[w] %= 10;
				w++;
				i /= 10;
			}
	}
	return w;
}

int main(int argc, char** argv) {
	int n,w;
	int S[100000]={0};
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		w = fn(i,S);	
	}
	for (int i=w-1;i>=0;i--)
		printf("%d",S[i]);
	return 0;
}
