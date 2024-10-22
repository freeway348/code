#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool fs(int m)
{
	if (m == 2)
		return true;
	else if (m>2)
		for (int i=2;i<m;i++)
			if (m%i == 0)
				return false;
			else 
				return true;
	else
		return false;	
}

int main(int argc, char** argv) {
	int maxn=0,minn=0x3f3f3f3f,arr[30]={0};
	string s;
	cin >> s;
	for (int i=0;i<s.size();i++)
	{
		++arr[s[i]-'a'];
	}
	for (int i=0;i<26;i++)
	{
		if (arr[i] > maxn)
			maxn = arr[i];
		if (arr[i] < minn && arr[i]!=0)
			minn = arr[i];
	}
	if (fs(maxn-minn))
		printf("Lucky Word\n%d",maxn-minn);
	else
		printf("No Answer\n0");
	return 0;
}
