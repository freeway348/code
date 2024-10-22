#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int arr[5][5];
	for (int i=0;i<5;i++)
		for (int j=0;j<5;j++)
			scanf("%d",&arr[i][j]);
	for (int i=0;i<5;i++)
		for (int j=0;j<5;j++)
			if (arr[i][j]==1)
				printf("%d",abs((2-i))+abs(2-j));
	return 0;
}
