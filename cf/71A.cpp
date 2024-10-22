#include <bits/stdc++.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int n,i;
	string p[102];
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		cin >> p[i];
	}
	for (i=0;i<n;i++)
	{
		if (p[i].size()>10)
			cout << p[i][0] << p[i].size()-2 << p[i][p[i].size()-1]<<endl;
		else 
			cout << p[i] << endl;
	}
	return 0;
}
