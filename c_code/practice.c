#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[]) {
	printf ("I love Luogu!\n");//1
	int all_num=10,A=2,uim=4,tail=all_num-A-uim;//2
	printf("%d %d\n",A+uim,tail);
	int all_ap=14;//3
	printf("%d\n%d\n%d\n",all_ap/4,all_ap-all_ap%4,all_ap%4);
	double kola=500;//4
	printf("%6g\n",kola/3);
	int longA=260,longB=220,vA=12,vB=20; //5
	printf("%d\n",(longA+longB)/(vA+vB));
	cout << sqrt(117) << endl;//6
	return 0;
}
