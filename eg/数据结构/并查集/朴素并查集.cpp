#include <bits/stdc++.h>
using namespace std;
#define N 100010
int p[N];//�洢���ڽڵ� 

int find ( int x )
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,t;
	cin >> n >> m >> t;
	for (int i = 0; i < 100010; i ++)	p[i] = i;
	for (int i = 0; i < m; i ++)
	{
		int a,b;
		cin >> a >> b;
		p[a] = find(a);//�ҵ����Ե����ڽڵ� 
		p[b] = find(b);
		if (p[a] != p[b]) p[find(b)] = p[a];
		//��p[b] = p[a]����wa��ԭ��
		// ��ѭ������Ϊ�˹��������ݹ�ϵ�Ĳ��鼯�������������ڵļ����޽���������Ҫ�ϲ� 
    	//��p[b] = p[a]ֻ�ǽ�b�����ָ����a�����ڽڵ㣬p[find(b)] = p[a]���ǽ��������Ϻϲ� 
	}
    while (t --)
    {
    	int x,y;
    	cin >> x >> y;
    	if (find(x) == find(y)) cout << "Yes" << endl;
    	else cout << "No" << endl;
	}
	return 0;
}
