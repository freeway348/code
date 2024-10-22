#define IOS ios::sync_with_stdio(false);cin.tie(0)
#include<bits/stdc++.h>
using namespace std;
#define mem(a,x) memset(a,x,sizeof(a))
#define pb(a) push_back(a)
#define rp(i,n) for(int i=0;i<n;i++)
#define rpn(i,n) for(int i=1;i<=n;i++)
struct goods{
	int type,no,score;
	goods(int t=0,int n=0,int s=0):type(t),no(n),score(s){}
	bool operator<(const goods& a)const{
		if(score==a.score){
			return type==a.type?no<a.no:type<a.type;
		}else return score>a.score;
	}
};
const int MAX_M=55;
unordered_map<int,int> sc[MAX_M];
int ans[MAX_M];//各类商品已选取数量
int scale[MAX_M];//各类商品最多选取数量
vector<int> v[MAX_M];//输出 
set<goods> st;
int main(){
	IOS;
	int m,n;
	cin>>m>>n;
	rp(i,n){//所有0~m-1类商品的第i个商品 
		int id,s;
		cin>>id>>s;
		rp(j,m){
			st.insert(goods(j,id,s));
			sc[j][id]=s;
		}
	}
	int op;
	cin>>op;
	rp(i,op){
		int no;
		cin>>no;
		if(no==1){
			int type,no,s;
			cin>>type>>no>>s;
			st.insert(goods(type,no,s));
			sc[type][no]=s;
		}else if(no==2){
			int type,no;
			cin>>type>>no;
			st.erase(goods(type,no,sc[type][no]));
		}else{
			int k;
			cin>>k;
			mem(ans,0),mem(scale,0);
			rp(j,m) cin>>scale[j];
			int total=0;
			for(auto e:st){
				if(ans[e.type]<scale[e.type]){
					v[e.type].pb(e.no);
					ans[e.type]++,total++;
					if(total>=k) break;
				}
			}
			rp(j,m){
				if(v[j].size()){
				//	sort(v[j].begin(),v[j].end());
					cout<<v[j][0];
					for(int pos=1;pos<v[j].size();pos++) cout<<' '<<v[j][pos];
					cout<<'\n';
					v[j].clear();
				}else cout<<"-1\n";
			}
		}
	}
	return 0;
}

