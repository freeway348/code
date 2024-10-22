#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int k=0,m,t,num=0;
	char ch[11],s[100000][1000];
	string str;
	scanf(" %s",ch);
	scanf(" %s",&str);;
	for (int i=0;i<str.size();i++)
	{
		if (str[i]==' ')
		{
			k++;
			m=i;
		}
		else 
		{
			s[k][i-m-1]=str[i];
		}
	}
	for (int i=k;i<=0;i++)
		if (strcmp(ch,s[i]))
		{
			t = i;
			num++;
		}
	return 0;
}
