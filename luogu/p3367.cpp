#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
// pair<int,pair<int,int>> p[N];
int q[N];

int find(int x)//找到并查集的顶点,并查集中的每个点都指向其顶点, p[x] 中存储的就是 x 所在并查集的顶点
{
	if (q[x] != x) q[x] = find(q[x]);
	return q[x];
}

int main()
{
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) q[i] = i;
	for (int i = 1; i <= m; i ++) 
	{
		int t,x,y;
		cin >> t >> x >> y;
		if (t == 1)
		{
			q[find(x)] = find(y);
			//如果写成 q[find(x)] = q[y],则会mle错误，写成q[find(x)] = y也会爆栈
			//第一个暂时不知道
			//第二个写法大概是因为当 q[x] = y,q[y] = x 时会陷入死递归(x,y在同一个集合中时)
		}
		else if (t == 2)
		{
			if (find(x) == find(y)) cout << 'Y' << '\n';
			else cout << 'N' << '\n';
		}
	}
	return 0;
}