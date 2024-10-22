#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 510, M = 200010,INF=0x3f3f3f3f;
int h[N],e[M],ne[M],w[M],tag[M],idx;
int dist[N][1010];//����С���ĳ���֮��һ�����ᳬ��1000
bool st[N][1010];//���ȥ�ر��Ҳ������
int n,m;

void add(int t,int a,int b,int c){
    e[idx]=b,w[idx]=c,tag[idx]=t,ne[idx]=h[a],h[a]=idx++;
}

struct Node{//��㣬����y�Ĳ�ͬ��x�ŵ㱻������ɵ�
    int x,y,d;
    bool operator<(const Node &p)const{
        return d>p.d;
    }
};
//���Ż���dijkstra
void dijkstra(){
    priority_queue<Node> heap;//priority_queueĬ�ϴ���ѣ�����Node��������Ϊ�������ʵ�����廹��С����
    heap.push({1,0,0});
    memset(dist,0x3f,sizeof dist);
    dist[1][0]=0;
    while(heap.size()){
        Node t=heap.top();
        heap.pop();
        if(st[t.x][t.y])continue;
        st[t.x][t.y]=true;
        for(int i=h[t.x];i!=-1;i=ne[i]){
            int k=e[i],weight=w[i];
            if(tag[i]){//С·
                if(t.y+weight<=1000)//����С���ĳ���֮��һ�����ᳬ��1000
                if(dist[k][t.y+weight]>t.d-t.y*t.y+(t.y+weight)*(t.y+weight)){
                    dist[k][t.y+weight]=t.d-t.y*t.y+(t.y+weight)*(t.y+weight);
                    if(dist[k][t.y+weight]<=INF) heap.push({k,t.y+weight,dist[k][t.y+weight]});
                }
            }
            else{//��·
                if(dist[k][0]>t.d+weight){
                    dist[k][0]=t.d+weight;
                    if(dist[k][0]<=INF) heap.push({k,0,dist[k][0]});
                }
            }
        }
    }
}

int main(){
    memset(h,-1,sizeof h);
    cin>>n>>m;
    int t,a,b,c;
    while(m--){
        cin>>t>>a>>b>>c;
        add(t,a,b,c);
        add(t,b,a,c);
    }
    dijkstra();
    int res=INF;
    for(int i=0;i<=1000;i++){
        res=min(res,dist[n][i]);
    }
    cout<<res<<endl;
}


