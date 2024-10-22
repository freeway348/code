#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct node
{
	int u;
	int v;
}p[100005];//记录邻居 
int main(int argc, char *argv[]) {
	int n,m,i,j,k,t,L;
	vector<int> num;//记录对区块链的操作
	vector<vector<int>> pr;//记录要输出的区块链 (节点的区块链)
	vector<int> ord;//记录节点的区块链的长度  
	num.resize(3);
	scanf("%d%d",&n,&m);
	for (i=0;i<m;i++)
	{
		scanf("%d%d",&p[i].u,&p[i].v);
	}
	scanf("%d%d",&t,&k);
	pr.resize(k);
	//已确保输入时刻b(i)<=b(i+1) 
	for (j=0;j<k;j++)
	{
		
	}
	return 0;
}
