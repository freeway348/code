#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int m,n,sum=0;
	scanf("%d%d",&m,&n);
	sum += n*(m/2);
	if (m%2 != 0)
		sum += n/2;
	printf("%d",sum);
	return 0;
}
