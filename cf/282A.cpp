#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int x=0,n;
	string s;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		cin >> s ;
		if (s[1] == '+')
			x++;
		else if (s[1] == '-')
			x--;
	}
	printf("%d",x);
	return 0;
}
