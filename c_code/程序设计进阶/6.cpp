#include<bits/stdc++.h>
using namespace std;
const int maxn=10000010;
int myget(char *b){
    char ch=getchar();
    if(ch==EOF)return -1;
    int i=0;
    while(ch!='\n'&&ch!=EOF){
        *(b+i)=ch;++i;
        ch=getchar();
    }return i;
}char a[21000000];
int main(){
    //freopen("init2.txt","r",stdin);
    int n,typ=0,lin=1,cnt=0,now=0,lonf=0;
    int w;cin>>w;getchar();
    int num=0;
    // 段落 1，项目 2，无类型0
    while((n=myget(a))!=-1){
        ++num;//cout<<num<<endl;
        int f=0;
        for(int i=0;i<n;++i){ if(a[i]!=' '){ f=1;break; } }
        //cout<<1<<' '<<lin<<' '<<cnt<<' '<<typ<<' '<<f<<endl;
        if(!f){
            lonf=1;
            continue;
        }
        if(a[0]=='*'&&a[1]==' '){
            if(lonf){
                if(now==1){typ=0;cnt=0;lin+=2;}
                if(cnt!=0){cnt=0;++lin;}
                if(typ!=0){typ=0;++lin;}
                lonf=0;
            }
            if(typ==2){if(cnt!=0||now==1)++lin;}
            else if(typ==1){++lin; if(cnt!=0)++lin;}
            typ=2; cnt=0; now=0;
            int l=0,r=-1;
            for(int i=2;i<n;++i)if(a[i]!=' '){l=i;break;}
            for(int i=n-1;i>=2;--i)if(a[i]!=' '){r=i;break;}
            if(r==-1)now=1;
            for(int i=l;i<=r;++i){
                if(cnt==0&&a[i]==' ')continue;
                if(cnt==0)cnt=3;
                ++cnt;
                if(cnt==w){cnt=0;++lin;}
            }
        }
        else if(typ==2&&(!lonf)&&a[0]==' '&&a[1]==' '){
            int l=0,r=-1;
            for(int i=2;i<n;++i)if(a[i]!=' '){l=i;break;}
            for(int i=n-1;i>=2;--i)if(a[i]!=' '){r=i;break;}
            if(cnt==w-1){++lin;cnt=0;}
            else if(cnt!=0)++cnt;
            for(int i=l;i<=r;++i){
                if(cnt==0&&a[i]==' ')continue;
                if(cnt==0)cnt=3;
                ++cnt;
                if(cnt==w){cnt=0;++lin;}
            }
        }
        else{
            if(lonf){
                if(now==1){typ=0;cnt=0;lin+=2;}
                if(cnt!=0){cnt=0;++lin;}
                if(typ!=0){typ=0;++lin;}
                lonf=0;
            }
            if(typ==1){
                if(cnt==w-1){++lin;cnt=0;}
                else if(cnt!=0)++cnt;
            }
            else if(typ==0)typ=1;
            else{ if(cnt!=0||now)++lin; ++lin;typ=1;cnt=0;}
            int l=0,r=-1;now=0;
            for(int i=0;i<n;++i)if(a[i]!=' '){l=i;break;}
            for(int i=n-1;i>=0;--i)if(a[i]!=' '){r=i;break;}
            for(int i=l;i<=r;++i){
                if(cnt==0&&a[i]==' ')continue;
                ++cnt;
                if(cnt==w){cnt=0;++lin;}
            }
        } //cout<<2<<' '<<lin<<' '<<cnt<<' '<<typ<<endl;
    }
    if(cnt==0&&!now)--lin;
    cout<<lin<<endl;
    return 0;
}
