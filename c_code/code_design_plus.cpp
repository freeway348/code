#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct node
{
	int u;
	int v;
}p[100005];//��¼�ھ� 
int main(int argc, char *argv[]) {
	int n,m,i,j,k,t,L;
	vector<int> num;//��¼���������Ĳ���
	vector<vector<int>> pr;//��¼Ҫ����������� (�ڵ��������)
	vector<int> ord;//��¼�ڵ���������ĳ���  
	num.resize(3);
	scanf("%d%d",&n,&m);
	for (i=0;i<m;i++)
	{
		scanf("%d%d",&p[i].u,&p[i].v);
	}
	scanf("%d%d",&t,&k);
	pr.resize(k);
	//��ȷ������ʱ��b(i)<=b(i+1) 
	for (j=0;j<k;j++)
	{
		
	}
	return 0;
}
