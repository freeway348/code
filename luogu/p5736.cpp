#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool fs (int m)
{
	if (m==1)
		return false;
	else
	{
		for (int i=2;i<m;i++)
		{
			if (m%i == 0)
				return false;
		}	
		return true;
	}
}

int main(int argc, char** argv) {
	int n;
	vector<int>arr;
	scanf("%d",&n);
	arr.resize(n);
	for (int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for (int i=0;i<n;i++)
		if (fs(arr[i]))
			cout << arr[i] <<" ";
	return 0;
}
