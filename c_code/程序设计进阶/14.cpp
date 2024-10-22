#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 10, INF = 0x3f3f3f3f;
int G[N][N];

bool check(int x){
    int ans;
    //ͬһ��
    for(int i=0;i<3;i++){
        ans=0;
        for(int j=0;j<3;j++){
            if(G[i][j]==x) ans++;
        }
        if(ans==3) return true;
    }
    //ͬһ��
    for(int j=0;j<3;j++){
        ans=0;
        for(int i=0;i<3;i++){
            if(G[i][j]==x) ans++;
        }
        if(ans==3) return true;
    }
    //ͬһ�Խ���
    if(G[0][0]==x&&G[1][1]==x&&G[2][2]==x) return true;
    else if(G[0][2]==x&&G[1][1]==x&&G[2][0]==x) return true;
    else return false;
}

int eval(){
    //ͳ�Ƶ�ǰ�ո���
    int emp=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(G[i][j]==0) emp++;
    //�ж�A�ĵ÷�
    if(check(1)) return emp+1;
    else if(check(2)) return -(emp+1);
    else if(emp==0) return 0;
    else return INF;
}

int dfs(int u){
    int s = eval();//���㵱ǰA�ĵ÷�
    if(s!=INF) return s;//�����ǰ�����жϷ�ֵ��ֱ�ӷ��ط�ֵ
    //Ŀǰ���жϲ���˭��˭Ӯ�򰴹����������
    if(u==1){//A��
        int ans=-INF;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(G[i][j]==0){
                    G[i][j]=1;
                    ans=max(dfs(2),ans);//ѡ��һ��B���߷����У�A���÷ַ�������ôΪ��B��ô�ߣ�
                    G[i][j]=0;//!!!dfsǧ��ǵûָ��ֳ�����ö���굱ǰλ����Ҫ����λ�ûָ�Ϊ��λ
                }
            }
        }
        return ans;
    }
    else{//B��
        int ans=INF;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(G[i][j]==0){
                    G[i][j]=2;
                    ans=min(dfs(1),ans);//ѡ��һ��A���߷����У�A��С�÷ַ�������ôΪ��A��ô�ߣ�
                    G[i][j]=0;//!!!dfsǧ��ǵûָ��ֳ�����ö���굱ǰλ����Ҫ����λ�ûָ�Ϊ��λ
                }
            }
        }
        return ans;
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                cin>>G[i][j];

        int res=dfs(1);//��ʾA��

        cout<<res<<endl;
    }
    return 0;
}


