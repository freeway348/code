#include <bits/stdc++.h>
using namespace std;
vector<int> v[10010];//存放n个部门的邻接表
//set<int> finds[10010];//存放每个部门知道的其它部门
bool visited[10010];
int finds[1010][1010];
//从节点i进行深度优先遍历 
void dfs(int root,int now){
	visited[now] = true;
//	if(root != now){
//		finds[root].insert(now);//记录访问到的店 
//		finds[now].insert(root);		
//	}
	finds[root][now] = 1;
	finds[now][root] = 1; 
	for(int i=0;i<v[now].size();i++){
		if(!visited[v[now][i]]){
			dfs(root,v[now][i]);
		}
	} 
} 
int main(){
	int n,m;
	if(n == 1){
		cout<<1<<endl;
		return 0;
	}
	scanf("%d%d",&n,&m);
	
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
	} 
	for(int i=1;i<=n;i++){
		fill(visited,visited+10010,false);
		dfs(i,i); 
	}
	int ans = 0;
//	for(int i=1;i<=n;i++){
//		if(finds[i].size() == n-1){
//			ans++;
//		}
//	}
	for(int i=1;i<=n;i++){
		bool flag = true;
		for(int j=1;j<=n;j++){
			if(finds[i][j] == 0){
				flag = false;
				break;
			}
		}
		if(flag) ans++;
	}
	cout<<ans;
	return 0;
} 

