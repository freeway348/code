#include<bits/stdc++.h>
using namespace std;
#define isOp(x,y) ((x^y)<0)
#define m_p(a,b) make_pair(a,b)
#define p_b(a) push_back(a)
#define rp(i,n) for(int i=0;i<n;i++)
#define rpn(i,n) for(int i=1;i<=n;i++)
#define l_b(a,n,x) lower_bound(a,a+n,x)-a
#define u_b(a,n,x) upper_bound(a,a+n,x)-a
const int MAX_N=301;
int n;
int s_2[MAX_N];//第二天的菜价
int s_1[MAX_N];
bool dp[MAX_N][MAX_N][MAX_N];
void dfs(int index,int p){//计算index+1家店第一天菜价
	if(p<1) return;
	if(index==n){
		if(((s_1[n-1]+p)>>1)==s_2[n]) s_1[n]=p;
		return;
	}
	s_1[index]=p;
	if(index==1){
		for(int i=0;i<=1;i++){
			int np=2*s_2[1]-p+i;
			if(!dp[1][p][np]){
				dfs(2,np);
				if(s_1[n]) break;
				dp[1][p][np]=true;
			}
		}
	}
	else{
		for(int i=0;i<=2;i++){
			int np=3*s_2[index]-s_1[index]-s_1[index-1]+i;
			if(!dp[index][p][np]){
				dfs(index+1,np);
				if(s_1[n]) break;
				dp[index][p][np]=true;
			}
		}		
	}
}
int main(){	
	cin>>n;
	rpn(i,n) cin>>s_2[i];
	for(int i=1;i<=(s_2[1]<<1);i++){
		dfs(1,i);
		if(s_1[n]) break;
	}
	cout<<s_1[1];
	for(int i=2;i<=n;i++) cout<<' '<<s_1[i];
	return 0;
}

