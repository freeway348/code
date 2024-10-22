#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 10, INF = 0x3f3f3f3f;
int G[N][N];

bool check(int x){
    int ans;
    //同一行
    for(int i=0;i<3;i++){
        ans=0;
        for(int j=0;j<3;j++){
            if(G[i][j]==x) ans++;
        }
        if(ans==3) return true;
    }
    //同一列
    for(int j=0;j<3;j++){
        ans=0;
        for(int i=0;i<3;i++){
            if(G[i][j]==x) ans++;
        }
        if(ans==3) return true;
    }
    //同一对角线
    if(G[0][0]==x&&G[1][1]==x&&G[2][2]==x) return true;
    else if(G[0][2]==x&&G[1][1]==x&&G[2][0]==x) return true;
    else return false;
}

int eval(){
    //统计当前空格数
    int emp=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(G[i][j]==0) emp++;
    //判断A的得分
    if(check(1)) return emp+1;
    else if(check(2)) return -(emp+1);
    else if(emp==0) return 0;
    else return INF;
}

int dfs(int u){
    int s = eval();//计算当前A的得分
    if(s!=INF) return s;//如果当前可以判断分值则直接返回分值
    //目前还判断不了谁输谁赢则按规则搜索情况
    if(u==1){//A走
        int ans=-INF;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(G[i][j]==0){
                    G[i][j]=1;
                    ans=max(dfs(2),ans);//选下一步B可走方案中，A最大得分方案（怎么为难B怎么走）
                    G[i][j]=0;//!!!dfs千万记得恢复现场，即枚举完当前位置需要将该位置恢复为空位
                }
            }
        }
        return ans;
    }
    else{//B走
        int ans=INF;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(G[i][j]==0){
                    G[i][j]=2;
                    ans=min(dfs(1),ans);//选下一步A可走方案中，A最小得分方案（怎么为难A怎么走）
                    G[i][j]=0;//!!!dfs千万记得恢复现场，即枚举完当前位置需要将该位置恢复为空位
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

        int res=dfs(1);//表示A走

        cout<<res<<endl;
    }
    return 0;
}


