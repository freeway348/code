#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int w;
	scanf("%d",&w);
	if (w == 2)
        printf("NO");
	else if (w%2 == 0)
		printf("YES");
	else 
		printf("NO");
	return 0;
}
