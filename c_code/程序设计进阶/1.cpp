#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define inf 0x3f3f3f3f
#define pii pair<int,int>
struct node{
    int t,id,cur,fa;
};
const int maxn=505;
int f[maxn][maxn];
vector<int>g[maxn];
int N,M;
int a,b,c,t,k;
int data[maxn];
vector<vector<int> > h;
queue<node>q;//<ti,id>
int main(){
    int u,v;
    ios::sync_with_stdio(false);
    memset(f,0,sizeof(f));
    cin>>N>>M;
    h.push_back(vector<int>(1,0));
    for(int i=1;i<=N;++i)data[i]=0;
    for(int i=1;i<=M;++i){
        cin>>u>>v;
        f[u][v]=f[v][u]=1;
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            if(i!=j&&f[i][j]){
                g[i].push_back(j);
            }
        }
    }
    cin>>t>>k;
    string str;getline(cin,str);
    while(k--){
        bool update=0;
        c=-1;
        getline(cin,str);
        stringstream ss(str);
        ss>>a;ss>>b;
        if(ss.str().size())ss>>c;
    //处理b时刻之前的操作
        while(!q.empty() && q.front().t<=b){
            node nd=q.front();q.pop();
            int ti=nd.t,id=nd.id,v=nd.cur,fa=nd.fa;
            if(h[id].size()<h[data[v]].size() ||
               (h[id].size()==h[data[v]].size() && h[id].back()>=h[data[v]].back()) )continue;
            else{
                data[v]=id;
                update=1;
            }
            for(int vv:g[v]){
                if(vv==fa)continue;
                q.push(node{ti+t,id,vv,v});
            }
        }
        if(c==-1){
            cout<<h[data[a]].size();
            for(int v:h[data[a]])cout<<' '<<v;cout<<endl;
        }else{
            vector<int>tmp=h[data[a]];
            tmp.push_back(c);
            h.push_back(tmp);
            data[a]=h.size()-1;
            update=1;
        }
        if(update){
            for(int v:g[a]){
                q.push(node{b+t,data[a],v,a});
            }
        }
    }
    return 0;
}
