#include <bits/stdc++.h>
using namespace std;
long long int p[10000010];
int k;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
inline int read(){	//¿ì¶Á 
    char ch=getchar();
	int x=0,f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    } 
	while('0'<=ch&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    } return x*f;
}

void quick_sort(int l,int r)
{
	if (l >= r) return;
	int i=l,j=r,x=p[i + j >> 1];
	while (i < j)
	{
		while (p[i] < x ) i++;
		while (p[j] > x ) j--;
		if (i < j) 
		{
			int t = p[i];
			p[i] = p[j];
			p[j] = t;
		}
	}
	if (k<i) quick_sort(l,j);
	else if (k == i) 
	{
		printf("%d",p[k]);
		exit(0);
	}
	else if (k>i) quick_sort(j+1,r);
	
}

int main(int argc, char** argv) {
	int n;
	scanf("%d%d",&n,&k);
	for (int i = 0 ; i < n ; i ++)
		p[i]=read();
	quick_sort(0,n-1);
	return 0;
}
