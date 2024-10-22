#include <bits/stdc++.h>
using namespace std;
int x,y;
int judge(int p[])
{
	int i,j,cnt = 0;
	for (i = 0;i < sizeof(p)-1; i ++)
	{
		for (j = i + 1; j < sizeof(p); j ++)
		{
			if ((p[i]+p[j])%x == 0 && (p[i]-p[j])%y == 0) cnt++;
		}
	}
	return cnt;
}

int main()
{
	int n,t,a[100010];
	int num[100010]={0};
	cin >> t;
	for (int i = 0; i < t;i ++)
	{
		memset(a,0,sizeof(a));
		cin >> n >> x >> y;
		for (int j = 0; j < n; j ++)
			cin >> a[j];
		num[i] = judge(a);
		
	}
	for (int i = 0; i < t;i ++)
		cout << num[i]<<endl;
	return 0;
}
