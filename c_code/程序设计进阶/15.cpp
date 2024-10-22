#include<bits/stdc++.h>
using namespace std;
const int maxx= 100+20;

int l;
int change(int shu){//如果小球的位置在边界之外，作对称处理模拟碰撞
    while(shu< 0||shu> l){
        while(shu< 0){
            shu= -shu;
        }
        while(shu> l){
            shu= 2*l- shu;
        }
    } 
    return shu;
}
int main(){

    int n, t;
    cin>>n>>l>>t;

    int vec[maxx];
    vector<int> pos(maxx, 0); 
    memset(vec, 0, sizeof(vec));
    for(int i= 0; i< n;i++)
     cin>>vec[i];



     for(int i= 0; i< n; i++){//记录从0到n的数分别是n个数中的从
      //大到小排第几
         int count= 0;
        for(int j= 0; j< n; j++){
            if(vec[i]> vec[j])
             count++;
         }
         pos[i]= count;
     }

     for(int i= 0; i< n; i++){

        vec[i]= change(vec[i]+ t);//先看成直线运动
     }

     sort(vec, vec+n);
     for(int  i= 0; i< n; i++){
        cout<<vec[pos[i]]<<' ';//对应输出相应排位的数
     }
     cout<<endl;
    return 0;
}


